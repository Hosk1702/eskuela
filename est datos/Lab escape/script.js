/**
 * Escena de Nivel Completado
 */
class LevelCompleteScene extends Phaser.Scene {
    constructor() {
        super({ key: 'LevelCompleteScene' });
    }

    init(data) {
        this.data = data;
    }

    create() {
        this.add.text(this.cameras.main.centerX, this.cameras.main.centerY - 100, 
            '¡Nivel ' + this.data.level + ' Completado!', 
            { fontSize: '40px', fill: '#0f0', fontFamily: 'Arial' }
        ).setOrigin(0.5);

        this.add.text(this.cameras.main.centerX, this.cameras.main.centerY, 
            'Puntuación: ' + this.data.score, 
            { fontSize: '32px', fill: '#FFD700', fontFamily: 'Arial' }
        ).setOrigin(0.5);

        this.add.text(this.cameras.main.centerX, this.cameras.main.centerY + 100, 
            'Haz click para continuar', 
            { fontSize: '24px', fill: '#888', fontFamily: 'Arial' }
        ).setOrigin(0.5);

        this.input.once('pointerdown', () => {
            this.scene.stop('LevelCompleteScene');
            this.scene.start('MazeScene', {
                health: this.data.health,
                inventory: this.data.inventory,
                level: this.data.level + 1, // Siguiente nivel
                score: this.data.score      // Mantiene la puntuación
            });
        });
    }
}

/**
 * Escena de Game Over
 */
class GameOverScene extends Phaser.Scene {
    constructor() {
        super({ key: 'GameOverScene' });
    }

    init(data) {
        this.data = data;
    }

    create() {
        this.add.text(this.cameras.main.centerX, this.cameras.main.centerY - 100, 
            'GAME OVER', 
            { fontSize: '40px', fill: '#f00', fontFamily: 'Arial' }
        ).setOrigin(0.5);

        this.add.text(this.cameras.main.centerX, this.cameras.main.centerY, 
            'Puntuación Final: ' + this.data.score, 
            { fontSize: '32px', fill: '#FFD700', fontFamily: 'Arial' }
        ).setOrigin(0.5);

        this.add.text(this.cameras.main.centerX, this.cameras.main.centerY + 100, 
            'Haz click para reiniciar', 
            { fontSize: '24px', fill: '#888', fontFamily: 'Arial' }
        ).setOrigin(0.5);

        this.input.once('pointerdown', () => {
            this.scene.stop('GameOverScene');
            // Reinicia con todo a 0
            this.scene.start('MazeScene', { 
                level: 1, 
                score: 0, 
                health: 100, 
                inventory: { keys: 0 } 
            });
        });
    }
}


/**
 * Escena Principal del Laberinto
 */
class MazeScene extends Phaser.Scene {
    constructor() {
        super({ key: 'MazeScene' });
        // Definiciones del laberinto
        this.cols = 25;
        this.rows = 20;
        this.cellSize = 45;

        this.mazeWidth = this.cols * this.cellSize;
        this.mazeHeight = this.rows * this.cellSize;

        this.grid = [];
        this.player = null;
        this.playerPos = { x: 0, y: 0 }; // Posición por defecto Nivel 1
        this.playerQuadrant = 0; // 0=TL, 1=TR, 2=BL, 3=BR
        this.specialDoorPos = { x: 0, y: 0 }; // Se establecerá aleatoriamente
        this.solutionPath = []; // Almacenará la ruta al éxito

        this.keys = [];
        this.doors = [];
        this.hearts = []; // Array para vidas
        this.traps = [];  // Array para trampas

        // --- NUEVO: Niebla de Guerra ---
        this.visitedGrid = [];
        this.fogGraphics = null;
        this.visitedGraphics = null;
        // ---

        // --- Configuración de Items ---
        this.maxMainKeys = 5; // Llaves amarillas en la ruta
        this.numDoorsToPlace = 5; // Puertas en la ruta
        this.doorSafeZone = 3; 
        this.numHearts = 3;  // Cuántos corazones poner (fuera de ruta)
        this.numTraps = 20;   // Cuántas trampas poner (fuera de ruta)
        
        // --- Arreglo para 98/99 HP ---
        this.isMoving = false; // Bloquea el movimiento hasta que se suelte la tecla

        // Estado del jugador
        this.health = 100;
        this.maxHealth = 100;
        this.inventory = { keys: 0 };
        this.level = 1;
        this.score = 0; // Puntuación

        // Referencias a la UI (HTML)
        this.healthBarEl = null;
        this.inventoryTextEl = null;
        this.levelTextEl = null;
        this.healthTextEl = null;
        this.scoreTextEl = null; 
    }

    init(data) {
        this.health = data.health || 100;
        this.inventory = data.inventory || { keys: 0 };
        this.level = data.level || 1;
        this.score = data.score || 0; 
        this.isMoving = false; // Resetea el bloqueo de movimiento
        
        // Posición aleatoria si no es el nivel 1
        if (this.level > 1) {
            this.playerQuadrant = Phaser.Math.Between(0, 3);
            const midX = Math.floor(this.cols / 2);
            const midY = Math.floor(this.rows / 2);
            
            let minX, maxX, minY, maxY;

            if (this.playerQuadrant === 0) { // Top-Left
                minX = 0; maxX = midX - 1; minY = 0; maxY = midY - 1;
            } else if (this.playerQuadrant === 1) { // Top-Right
                minX = midX; maxX = this.cols - 1; minY = 0; maxY = midY - 1;
            } else if (this.playerQuadrant === 2) { // Bottom-Left
                minX = 0; maxX = midX - 1; minY = midY; maxY = this.rows - 1;
            } else { // Bottom-Right
                minX = midX; maxX = this.cols - 1; minY = midY; maxY = this.rows - 1;
            }

            this.playerPos = {
                x: Phaser.Math.Between(minX, maxX),
                y: Phaser.Math.Between(minY, maxY)
            };

        } else {
            this.playerQuadrant = 0;
            this.playerPos = { x: 0, y: 0 };
        }
    }

    preload() {
        this.load.image('player', 'player.png');
    }

    create() {
        // --- Referencias a la UI de HTML ---
        this.healthBarEl = document.getElementById('health-bar');
        this.inventoryTextEl = document.getElementById('key-text');
        this.levelTextEl = document.getElementById('level-text');
        this.healthTextEl = document.getElementById('health-text'); 
        this.scoreTextEl = document.getElementById('score-text'); 

        // --- Configuración del Laberinto ---
        const offsetX = (this.sys.game.config.width - this.mazeWidth) / 2;
        const offsetY = (this.sys.game.config.height - this.mazeHeight) / 2;
        this.offsetX = offsetX;
        this.offsetY = offsetY;

        // 1. Generar la cuadrícula y el laberinto
        this.generateGrid();
        this.generateMaze(); 
        
        // --- NUEVO: Generar cuadrícula de niebla ---
        this.generateVisitedGrid();

        // 2. Dibujar el laberinto
        const mazeGraphics = this.add.graphics();
        mazeGraphics.x = offsetX;
        mazeGraphics.y = offsetY;
        this.drawMaze(mazeGraphics);
        mazeGraphics.setDepth(0); // Fondo

        // --- NUEVO: Gráficos de Niebla y Camino ---
        this.visitedGraphics = this.add.graphics();
        this.visitedGraphics.setDepth(1); // Encima del laberinto
        this.fogGraphics = this.add.graphics();
        this.fogGraphics.setDepth(10); // Encima de todo, excepto el jugador
        
        // 3. Colocar la salida especial (aleatoria y distante)
        this.placeSpecialDoor();
        this.specialDoor.setDepth(3); // Encima del camino, debajo de la niebla

        // 4. Encontrar el camino a la salida
        this.solutionPath = this.findSolutionPath(this.playerPos, this.specialDoorPos);
        
        if (!this.solutionPath) {
            console.error("¡No se encontró solución! Reiniciando...");
            this.scene.restart({
                level: this.level,
                score: this.score,
                health: this.health,
                inventory: this.inventory
            });
            return;
        }

        // 5. Grupos para llaves y puertas (Contenedores de Gráficos)
        this.keyGroup = this.add.group();
        this.doorGroup = this.add.group();
        this.heartGroup = this.add.group(); 
        this.trapGroup = this.add.group();  

        // 6. Colocar llaves y puertas (basado en la solución + exploración)
        this.placeItems();
        
        // --- NUEVO: Poner items encima del camino, debajo de la niebla ---
        this.keyGroup.setDepth(3);
        this.doorGroup.setDepth(3);
        this.heartGroup.setDepth(3);
        this.trapGroup.setDepth(3);

        // 7. Crea el jugador
        this.player = this.add.sprite(
            this.playerPos.x * this.cellSize + this.cellSize / 2 + offsetX,
            this.playerPos.y * this.cellSize + this.cellSize / 2 + offsetY,
            'player'
        );
        this.player.setScale(0.8 * this.cellSize / this.player.width);
        this.player.setDepth(11); // El jugador siempre encima de todo

        // 8. Iniciar UI y Controles
        this.updateUI(); 

        this.cursors = this.input.keyboard.createCursorKeys();
        this.input.keyboard.on('keydown', this.handlePlayerMove, this);
        this.input.keyboard.on('keyup', this.handlePlayerUp, this);
        
        // 9. Comprobar si el jugador empezó encima de un item
        this.checkCellForItems(this.playerPos.x, this.playerPos.y);

        // --- NUEVO: Primera actualización de la niebla ---
        this.visitedGrid[this.playerPos.y][this.playerPos.x] = true;
        this.updateFogAndPath();
    }
    
    // --- Métodos de UI (Actualizan el HTML) ---
    updateUI() {
        this.updateHealthBar();
        this.updateInventoryText();
        this.updateHealthText(); 
        this.updateScoreText(); 
        if (this.levelTextEl) {
            this.levelTextEl.innerText = this.level;
        }
    }
    
    updateScoreText() {
        if (!this.scoreTextEl) return;
        this.scoreTextEl.innerText = this.score;
    }

    updateHealthBar() {
        if (!this.healthBarEl) return;
        const percent = this.maxHealth > 0 ? (this.health / this.maxHealth) * 100 : 0;
        const barColor = this.health > (this.maxHealth * 0.3) ? '#00ff00' : '#ff0000';
        const barWidthPercent = percent;
        this.healthBarEl.style.width = barWidthPercent + '%';
        this.healthBarEl.style.backgroundColor = barColor;
    }

    updateHealthText() {
        if (!this.healthTextEl) return;
        this.healthTextEl.innerText = this.health + ' HP';
    }

    updateInventoryText() {
        if (!this.inventoryTextEl) return;
        this.inventoryTextEl.innerText = 'x ' + this.inventory.keys;
    }

    // --- NUEVAS FUNCIONES DE NIEBLA ---
    generateVisitedGrid() {
        this.visitedGrid = [];
        for (let y = 0; y < this.rows; y++) {
            this.visitedGrid[y] = [];
            for (let x = 0; x < this.cols; x++) {
                this.visitedGrid[y][x] = false;
            }
        }
    }

    getVisibleCells() {
        const px = this.playerPos.x;
        const py = this.playerPos.y;
        const cells = [{ x: px, y: py }]; // Celda actual

        // 8 celdas adyacentes
        for (let x = -1; x <= 1; x++) {
            for (let y = -1; y <= 1; y++) {
                if (x === 0 && y === 0) continue;
                const newX = px + x;
                const newY = py + y;
                if (newX >= 0 && newX < this.cols && newY >= 0 && newY < this.rows) {
                    cells.push({ x: newX, y: newY });
                }
            }
        }
        return cells;
    }

    updateItemVisibility(visibleCells) {
        const checkVisibility = (item) => {
            const isVisible = visibleCells.some(c => c.x === item.x && c.y === item.y);
            item.sprite.setVisible(isVisible);
        };

        this.keys.forEach(checkVisibility);
        this.doors.forEach(checkVisibility);
        this.traps.forEach(checkVisibility);
        this.hearts.forEach(checkVisibility);
        
        // Tratar la puerta especial como un item
        checkVisibility({
            sprite: this.specialDoor,
            x: this.specialDoorPos.x,
            y: this.specialDoorPos.y
        });
    }

    updateFogAndPath() {
        this.fogGraphics.clear();
        this.visitedGraphics.clear();

        this.fogGraphics.fillStyle(0x000000, 1);
        this.visitedGraphics.fillStyle(0xffffff, 0.25); // Blanco semi-transparente

        const worldX = (x) => x * this.cellSize + this.offsetX;
        const worldY = (y) => y * this.cellSize + this.offsetY;
        
        const visibleCells = this.getVisibleCells();

        for (let y = 0; y < this.rows; y++) {
            for (let x = 0; x < this.cols; x++) {
                const isVisited = this.visitedGrid[y][x];
                const isVisible = visibleCells.some(c => c.x === x && c.y === y);

                if (isVisited) {
                    // Si está visitada, píntala de blanco
                    this.visitedGraphics.fillRect(worldX(x), worldY(y), this.cellSize, this.cellSize);
                }
                
                if (!isVisited && !isVisible) {
                    // Si NO está visitada Y NO es visible (adyacente), cúbrela de niebla
                    this.fogGraphics.fillRect(worldX(x), worldY(y), this.cellSize, this.cellSize);
                }
            }
        }
        
        // --- NUEVO: Actualizar visibilidad de items ---
        this.updateItemVisibility(visibleCells);
    }

    // --- Colocación de Objetos ---
    placeSpecialDoor() {
        const midX = Math.floor(this.cols / 2);
        const midY = Math.floor(this.rows / 2);
        let minX, maxX, minY, maxY;
        const oppositeQuadrant = (this.playerQuadrant + 2) % 4; 
        if (oppositeQuadrant === 0) { minX = 0; maxX = midX - 1; minY = 0; maxY = midY - 1;
        } else if (oppositeQuadrant === 1) { minX = midX; maxX = this.cols - 1; minY = 0; maxY = midY - 1;
        } else if (oppositeQuadrant === 2) { minX = 0; maxX = midX - 1; minY = midY; maxY = this.rows - 1;
        } else { minX = midX; maxX = this.cols - 1; minY = midY; maxY = this.rows - 1; }
        do {
            this.specialDoorPos.x = Phaser.Math.Between(minX, maxX);
            this.specialDoorPos.y = Phaser.Math.Between(minY, maxY);
        } while (this.specialDoorPos.x === this.playerPos.x && this.specialDoorPos.y === this.playerPos.y)
        const portalSize = this.cellSize * 0.8;
        this.specialDoor = this.add.graphics();
        this.specialDoor.fillStyle(0x9400D3, 1); // Púrpura
        this.specialDoor.fillRect(
            this.specialDoorPos.x * this.cellSize + (this.cellSize - portalSize) / 2 + this.offsetX,
            this.specialDoorPos.y * this.cellSize + (this.cellSize - portalSize) / 2 + this.offsetY,
            portalSize,
            portalSize
        );
        this.specialDoor.setVisible(false); // NUEVO: Oculto por niebla
    }

    isCellOccupied(x, y) {
        if (x === this.playerPos.x && y === this.playerPos.y) return true;
        if (x === this.specialDoorPos.x && y === this.specialDoorPos.y) return true;
        if (this.getKeyAt(x, y)) return true;
        if (this.getDoorAt(x, y)) return true;
        if (this.getHeartAt(x, y)) return true;
        if (this.getTrapAt(x, y)) return true;
        return false;
    }

    placeItems() {
        const itemSize = this.cellSize * 0.6;
        const itemOffset = (this.cellSize - itemSize) / 2;
        const trapSize = itemSize * 0.8; 
        const trapOffset = (this.cellSize - trapSize) / 2;

        const worldX = (posX) => posX * this.cellSize + this.offsetX;
        const worldY = (posY) => posY * this.cellSize + this.offsetY;

        const pathLength = this.solutionPath.length;
        const midPoint = Math.floor(pathLength / 2);
        
        let keyPath = this.solutionPath.slice(this.doorSafeZone, midPoint);
        let doorPath = this.solutionPath.slice(midPoint, pathLength - this.doorSafeZone);

        Phaser.Utils.Array.Shuffle(keyPath);
        Phaser.Utils.Array.Shuffle(doorPath);

        // Colocar 5 Llaves (Amarillas) en la ZONA DE LLAVES
        for (let i = 0; i < this.maxMainKeys; i++) {
            let pos = keyPath.pop(); 
            if (!pos) { pos = this.getRandomEmptyCell(true, true, false); }
            if (!pos || this.isCellOccupied(pos.x, pos.y)) {
                 pos = this.getRandomEmptyCell(true, true, false); 
                if (!pos) continue; 
            }
            const keyGraphic = this.add.graphics();
            keyGraphic.fillStyle(0xFFFF00, 1); 
            keyGraphic.fillRect(worldX(pos.x) + itemOffset, worldY(pos.y) + itemOffset, itemSize, itemSize);
            keyGraphic.setVisible(false); // NUEVO: Oculto por niebla
            this.keyGroup.add(keyGraphic);
            this.keys.push({ x: pos.x, y: pos.y, sprite: keyGraphic });
        }
        
        // Colocar 5 Puertas (Marrones) en la ZONA DE PUERTAS
        for (let i = 0; i < this.numDoorsToPlace; i++) {
             let pos = doorPath.pop();
             if (!pos) { pos = this.getRandomEmptyCell(false, true, false); }
             if (!pos || this.isCellOccupied(pos.x, pos.y)) {
                pos = this.getRandomEmptyCell(false, true, false); 
                if (!pos) continue;
            }
            const cell = this.grid[pos.y][pos.x];
            const isVerticalPassage = !cell.walls.top && !cell.walls.bottom && cell.walls.left && cell.walls.right;
            const doorGraphic = this.add.graphics();
            doorGraphic.fillStyle(0x8B4513, 1); // Marrón
            let doorWidth, doorHeight;
            if (isVerticalPassage) { doorWidth = this.cellSize * 0.2; doorHeight = this.cellSize * 0.8;
            } else { doorWidth = this.cellSize * 0.8; doorHeight = this.cellSize * 0.2; }
            doorGraphic.fillRect(
                worldX(pos.x) + (this.cellSize - doorWidth) / 2,
                worldY(pos.y) + (this.cellSize - doorHeight) / 2,
                doorWidth, doorHeight
            );
            doorGraphic.setVisible(false); // NUEVO: Oculto por niebla
            this.doorGroup.add(doorGraphic);
            this.doors.push({ x: pos.x, y: pos.y, sprite: doorGraphic });
        }
        
        // Colocar 3 Corazones (Rosas) FUERA de la ruta
        for (let i = 0; i < this.numHearts; i++) {
            const pos = this.getRandomEmptyCell(true, false, true); 
            if (pos) { 
                const heartGraphic = this.add.graphics();
                heartGraphic.fillStyle(0xFF00FF, 1); // Rosa
                heartGraphic.fillRect(worldX(pos.x) + itemOffset, worldY(pos.y) + itemOffset, itemSize, itemSize);
                heartGraphic.setVisible(false); // NUEVO: Oculto por niebla
                this.heartGroup.add(heartGraphic);
                this.hearts.push({ x: pos.x, y: pos.y, sprite: heartGraphic });
            }
        }

        // Colocar 20 Trampas (Rojas) FUERA de la ruta principal
        for (let i = 0; i < this.numTraps; i++) {
             const pos = this.getRandomEmptyCell(false, false, true); 
            if (pos) {
                const trapGraphic = this.add.graphics();
                trapGraphic.fillStyle(0xFF0000, 1); // Rojo
                trapGraphic.fillRect(worldX(pos.x) + trapOffset, worldY(pos.y) + trapOffset, trapSize, trapSize);
                trapGraphic.setVisible(false); // NUEVO: Oculto por niebla
                this.trapGroup.add(trapGraphic);
                this.traps.push({ x: pos.x, y: pos.y, sprite: trapGraphic });
            }
        }
    }

    getRandomEmptyCell(isItem = false, mustBeOnPath = false, mustBeOffPath = false) {
        let x, y, cell;
        let attempts = 0; 
        const maxAttempts = 5000;
        let onSolutionPath = false;
        do {
            x = Phaser.Math.Between(0, this.cols - 1);
            y = Phaser.Math.Between(0, this.rows - 1);
            cell = this.grid[y][x];
            attempts++;
            if (attempts > maxAttempts) {
                 console.warn(`No se pudo encontrar una celda vacía (Item: ${isItem}, OnPath: ${mustBeOnPath}, OffPath: ${mustBeOffPath}).`);
                 return null;
            }
            if (this.solutionPath.length > 0) {
                 onSolutionPath = this.solutionPath.some(p => p.x === x && p.y === y);
            }
            const isAdjacentToPlayer = 
                (Math.abs(x - this.playerPos.x) === 1 && y === this.playerPos.y) ||
                (Math.abs(y - this.playerPos.y) === 1 && x === this.playerPos.x);   
        } while (
            this.isCellOccupied(x, y) ||
            (!isItem && mustBeOnPath && isAdjacentToPlayer) || 
            (isItem && (cell.walls.top && cell.walls.bottom)) || 
            (isItem && (cell.walls.left && cell.walls.right)) ||
            (mustBeOnPath && !onSolutionPath) || 
            (mustBeOffPath && onSolutionPath)
        );
        return { x, y };
    }


    // --- Métodos de Pathfinding (BFS) ---
    findSolutionPath(start, end) {
        let queue = [];
        let visited = new Set();
        queue.push([start]);
        visited.add(`${start.x},${start.y}`);
        while (queue.length > 0) {
            let path = queue.shift();
            let pos = path[path.length - 1];
            if (!this.grid[pos.y] || !this.grid[pos.y][pos.x]) { console.warn("Pathfinding en celda inválida:", pos.y, pos.x); continue; }
            let cell = this.grid[pos.y][pos.x];
            if (pos.x === end.x && pos.y === end.y) { return path; }
            const neighbors = [];
            if (!cell.walls.top) neighbors.push({ x: pos.x, y: pos.y - 1 });
            if (!cell.walls.bottom) neighbors.push({ x: pos.x, y: pos.y + 1 });
            if (!cell.walls.left) neighbors.push({ x: pos.x - 1, y: pos.y });
            if (!cell.walls.right) neighbors.push({ x: pos.x + 1, y: pos.y });
            for (const neighbor of neighbors) {
                const visitedKey = `${neighbor.x},${neighbor.y}`;
                if (neighbor.x >= 0 && neighbor.x < this.cols &&
                    neighbor.y >= 0 && neighbor.y < this.rows &&
                    !visited.has(visitedKey)) {
                    visited.add(visitedKey);
                    let newPath = [...path, neighbor];
                    queue.push(newPath);
                }
            }
        }
        return null;
    }

    // --- Métodos auxiliares (Llaves, Puertas, Nivel) ---
    getKeyAt(x, y) { return this.keys.find(key => key.x === x && key.y === y); }
    getDoorAt(x, y) { return this.doors.find(door => door.x === x && door.y === y); }
    getHeartAt(x, y) { return this.hearts.find(heart => heart.x === x && heart.y === y); }
    getTrapAt(x, y) { return this.traps.find(trap => trap.x === x && trap.y === y); }
    removeKey(key) { if (!key) return; key.sprite.destroy(); this.keys.splice(this.keys.indexOf(key), 1); }
    removeDoor(door) { if (!door) return; door.sprite.destroy(); this.doors.splice(this.doors.indexOf(door), 1); }
    removeHeart(heart) { if (!heart) return; heart.sprite.destroy(); this.hearts.splice(this.hearts.indexOf(heart), 1); }
    removeTrap(trap) { if (!trap) return; trap.sprite.destroy(); this.traps.splice(this.traps.indexOf(trap), 1); }

    // --- Lógica de Siguiente Nivel ---
    nextLevel() {
        this.isMoving = true; // Bloquea el movimiento
        this.input.keyboard.off('keydown', this.handlePlayerMove, this);
        this.input.keyboard.off('keyup', this.handlePlayerUp, this);

        this.score += 500; // Bonus por pasar de nivel
        this.updateScoreText();

        this.scene.stop('MazeScene');
        this.scene.start('LevelCompleteScene', {
            health: this.health,
            inventory: this.inventory,
            level: this.level, // Pasa el nivel actual
            score: this.score
        });
    }

    // --- Métodos del laberinto (Generación 100% conectada) ---
    generateGrid() {
        for (let y = 0; y < this.rows; y++) {
            this.grid[y] = [];
            for (let x = 0; x < this.cols; x++) {
                this.grid[y][x] = {
                    x, y,
                    walls: { top: true, right: true, bottom: true, left: true },
                    visited: false,
                };
            }
        }
    }

    generateMaze() {
        const stack = [];
        let current = this.grid[0][0]; // Siempre empieza en (0,0) para asegurar conexión
        current.visited = true;
        let unvisited = this.rows * this.cols - 1;

        while (unvisited > 0) {
            const neighbors = this.getUnvisitedNeighbors(current);
            if (neighbors.length > 0) {
                const next = neighbors[Math.floor(Math.random() * neighbors.length)];
                stack.push(current);
                this.removeWalls(current, next);
                current = next;
                current.visited = true;
                unvisited--;
            } else if (stack.length > 0) {
                current = stack.pop();
            } 
        }
    }

    getUnvisitedNeighbors(cell) {
        const neighbors = [];
        const { x, y } = cell;
        if (y > 0 && !this.grid[y - 1][x].visited) neighbors.push(this.grid[y - 1][x]);
        if (x < this.cols - 1 && !this.grid[y][x + 1].visited) neighbors.push(this.grid[y][x + 1]);
        if (y < this.rows - 1 && !this.grid[y + 1][x].visited) neighbors.push(this.grid[y + 1][x]);
        if (x > 0 && !this.grid[y][x - 1].visited) neighbors.push(this.grid[y][x - 1]);
        return neighbors;
    }

    removeWalls(a, b) {
        const dx = a.x - b.x;
        if (dx === 1) { a.walls.left = false; b.walls.right = false; } 
        else if (dx === -1) { a.walls.right = false; b.walls.left = false; }
        const dy = a.y - b.y;
        if (dy === 1) { a.walls.top = false; b.walls.bottom = false; } 
        else if (dy === -1) { a.walls.bottom = false; b.walls.top = false; }
    }

    drawMaze(graphics) {
        graphics.lineStyle(2, 0x0000ff); 
        for (let y = 0; y < this.rows; y++) {
            for (let x = 0; x < this.cols; x++) {
                const cell = this.grid[y][x];
                const cx = x * this.cellSize;
                const cy = y * this.cellSize;
                if (cell.walls.top) graphics.lineBetween(cx, cy, cx + this.cellSize, cy);
                if (cell.walls.right) graphics.lineBetween(cx + this.cellSize, cy, cx + this.cellSize, cy + this.cellSize);
                if (cell.walls.bottom) graphics.lineBetween(cx, cy + this.cellSize, cx + this.cellSize, cy + this.cellSize);
                if (cell.walls.left) graphics.lineBetween(cx, cy, cx, cy + this.cellSize);
            }
        }
    }

    // --- Helper para recoger items ---
    checkCellForItems(x, y) {
        // 3a. Comprobar si hay una llave
        const key = this.getKeyAt(x, y);
        if (key && key.sprite.visible) { // Solo coger si es visible
            this.inventory.keys++;
            this.score += 100; // +100 puntos por llave
            this.removeKey(key);
            this.updateInventoryText();
            this.updateScoreText();
        }

        // 3b. Comprobar si hay un corazón
        const heart = this.getHeartAt(x, y);
        if (heart && heart.sprite.visible) {
            this.health = Math.min(this.health + 10, this.maxHealth); // Gana 10 HP
            this.removeHeart(heart);
            this.updateHealthBar();
            this.updateHealthText();
        }

        // 3c. Comprobar si hay una trampa
        const trap = this.getTrapAt(x, y);
        if (trap && trap.sprite.visible) {
            this.health = Math.max(this.health - 34, 0); // DAÑO DE 34 HP
            this.removeTrap(trap);
            this.updateHealthBar();
            this.updateHealthText();
            
            if (this.health <= 0) {
                this.isMoving = true; // Bloquea el movimiento
                this.input.keyboard.off('keydown', this.handlePlayerMove, this);
                this.input.keyboard.off('keyup', this.handlePlayerUp, this);
                this.scene.stop('MazeScene');
                this.scene.start('GameOverScene', { score: this.score });
            }
        }

        // 3d. Comprobar si ha llegado a la puerta especial
        if (x === this.specialDoorPos.x && y === this.specialDoorPos.y && this.health > 0) {
            this.nextLevel();
        }
    }

    // --- Lógica de movimiento (Con arreglo de doble-daño) ---
    handlePlayerUp(event) {
        const codes = ['ArrowUp', 'ArrowDown', 'ArrowLeft', 'ArrowRight'];
        if (codes.includes(event.code)) {
            this.isMoving = false; // Permite el próximo movimiento
        }
    }
    
    handlePlayerMove(event) {
        // ARREGLO 98/99HP: Comprobar si ya nos estamos moviendo
        if (this.isMoving) {
            return; 
        }

        if (this.health <= 0) return;

        const currentCell = this.grid[this.playerPos.y][this.playerPos.x];
        let targetX = this.playerPos.x;
        let targetY = this.playerPos.y;
        let direction = null;
        let moved = false;

        switch (event.code) {
            case 'ArrowUp': targetY--; direction = 'top'; break;
            case 'ArrowDown': targetY++; direction = 'bottom'; break;
            case 'ArrowLeft': targetX--; direction = 'left'; break;
            case 'ArrowRight': targetX++; direction = 'right'; break;
        }

        if (direction === null) return;

        // 1. Comprobar si hay una puerta en el destino
        const door = this.getDoorAt(targetX, targetY);
        if (door && door.sprite.visible) { // Solo interactuar si es visible
            if (this.inventory.keys > 0) {
                this.inventory.keys--;
                this.removeDoor(door);
                this.updateInventoryText();
            } else {
                return; // Puerta cerrada, no te muevas
            }
        }
        
        // 2. Comprobar si hay una pared
        if (!currentCell.walls[direction]) {
            this.playerPos.x = targetX;
            this.playerPos.y = targetY;
            moved = true;
        }

        // 3. Comprobar acciones DESPUÉS de moverse
        if (moved) {
            // ARREGLO 98/99HP: Bloquear movimiento hasta que se suelte la tecla
            this.isMoving = true;

            this.player.setPosition(
                this.playerPos.x * this.cellSize + this.cellSize / 2 + this.offsetX,
                this.playerPos.y * this.cellSize + this.cellSize / 2 + this.offsetY
            );

            // Marcar la nueva celda como visitada
            this.visitedGrid[this.playerPos.y][this.playerPos.x] = true;

            // Comprobar la nueva celda para llaves, corazones, trampas o la salida
            // (Esto debe ocurrir ANTES de actualizar la niebla, para que se vean)
            this.checkCellForItems(this.playerPos.x, this.playerPos.y);

            // --- NUEVO: Actualizar niebla y camino ---
            this.updateFogAndPath();
        }
    }
}

// Configuración general del juego
const config = {
    type: Phaser.AUTO,
    width: 1180, 
    height: 980,
    parent: 'game', 
    backgroundColor: '#000000',
    scene: [MazeScene, LevelCompleteScene, GameOverScene],
    scale: {
        mode: Phaser.Scale.FIT, // Ajustar al contenedor
        autoCenter: Phaser.Scale.CENTER_BOTH
    }
};

// Inicializa el juego con la configuración
const game = new Phaser.Game(config);