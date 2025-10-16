class MazeScene extends Phaser.Scene {
    constructor() {
        super({ key: 'MazeScene' });
        // Definimos el número de columnas y filas
        this.cols = 25; // Ancho del laberinto en casillas
        this.rows = 20; // Alto del laberinto en casillas
        this.cellSize = 45; // Tamaño de cada casilla en píxeles (puedes ajustarlo si el laberinto queda muy grande o pequeño)

        this.mazeWidth = this.cols * this.cellSize;
        this.mazeHeight = this.rows * this.cellSize;

        this.grid = [];
        this.player = null;
        this.playerPos = { x: 0, y: 0 }; // Posición inicial del jugador
        this.exitPos = { x: this.cols - 1, y: this.rows - 1 }; // Posición de salida
    }

    preload() {
        // Carga el personaje que creamos previamente. Asegúrate de tener 'player.png' en tu carpeta.
        this.load.image('player', 'player.png');
        
    }

    create() {
        // Calcula los márgenes para centrar el laberinto
        const offsetX = (this.sys.game.config.width - this.mazeWidth) / 2;
        const offsetY = (this.sys.game.config.height - this.mazeHeight) / 2;

        this.generateGrid();
        this.generateMaze();

        const mazeGraphics = this.add.graphics();
        // Mueve el origen del dibujo para centrar el laberinto
        mazeGraphics.x = offsetX;
        mazeGraphics.y = offsetY;
        this.drawMaze(mazeGraphics);

        // Crea el jugador
        this.player = this.add.sprite(
            this.playerPos.x * this.cellSize + this.cellSize / 2 + offsetX,
            this.playerPos.y * this.cellSize + this.cellSize / 2 + offsetY,
            'player'
        );
        // Ajusta la escala del jugador para que se ajuste a la casilla
        this.player.setScale(0.8 * this.cellSize / this.player.width);

        // Crea la salida
        this.exit = this.add.sprite(
            this.exitPos.x * this.cellSize + this.cellSize / 2 + offsetX,
            this.exitPos.y * this.cellSize + this.cellSize / 2 + offsetY,
            'exit' // Asegúrate de tener 'exit.png'
        );
        this.exit.setScale(0.8 * this.cellSize / this.exit.width);


        this.cursors = this.input.keyboard.createCursorKeys();
        this.input.keyboard.on('keydown', this.handlePlayerMove, this);
    }

    generateGrid() {
        for (let y = 0; y < this.rows; y++) {
            this.grid[y] = [];
            for (let x = 0; x < this.cols; x++) {
                this.grid[y][x] = {
                    x,
                    y,
                    walls: { top: true, right: true, bottom: true, left: true },
                    visited: false,
                };
            }
        }
    }

    generateMaze() {
        const stack = [];
        let current = this.grid[0][0];
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
        if (dx === 1) {
            a.walls.left = false;
            b.walls.right = false;
        } else if (dx === -1) {
            a.walls.right = false;
            b.walls.left = false;
        }
        const dy = a.y - b.y;
        if (dy === 1) {
            a.walls.top = false;
            b.walls.bottom = false;
        } else if (dy === -1) {
            a.walls.bottom = false;
            b.walls.top = false;
        }
    }

    drawMaze(graphics) {
        graphics.lineStyle(2, 0x0000ff); // Muros azules
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

    handlePlayerMove(event) {
        const currentCell = this.grid[this.playerPos.y][this.playerPos.x];
        let moved = false;

        switch (event.code) {
            case 'ArrowUp':
                if (!currentCell.walls.top) {
                    this.playerPos.y--;
                    moved = true;
                }
                break;
            case 'ArrowDown':
                if (!currentCell.walls.bottom) {
                    this.playerPos.y++;
                    moved = true;
                }
                break;
            case 'ArrowLeft':
                if (!currentCell.walls.left) {
                    this.playerPos.x--;
                    moved = true;
                }
                break;
            case 'ArrowRight':
                if (!currentCell.walls.right) {
                    this.playerPos.x++;
                    moved = true;
                }
                break;
        }

        if (moved) {
            // Calcula los márgenes para centrar el laberinto nuevamente
            const offsetX = (this.sys.game.config.width - this.mazeWidth) / 2;
            const offsetY = (this.sys.game.config.height - this.mazeHeight) / 2;

            this.player.setPosition(
                this.playerPos.x * this.cellSize + this.cellSize / 2 + offsetX,
                this.playerPos.y * this.cellSize + this.cellSize / 2 + offsetY
            );

            // Comprobar si el jugador ha llegado a la salida
            if (this.playerPos.x === this.exitPos.x && this.playerPos.y === this.exitPos.y) {
                alert('¡Has escapado del laberinto!');
                // Aquí podrías reiniciar la escena, cargar otra, etc.
                this.scene.restart();
            }
        }
    }
}

// Configuración general del juego
const config = {
    type: Phaser.AUTO,
    // El ancho y alto del lienzo del juego ahora se ajustan para el laberinto + un pequeño margen
    // 20 casillas * 20 px/casilla = 400px de ancho
    // 25 casillas * 20 px/casilla = 500px de alto
    // Añadimos un pequeño margen para que el laberinto no esté pegado a los bordes del lienzo
    width: 1100 + 40, // 400px de laberinto + 40px de margen (20 a cada lado)
    height: 900 + 40, // 500px de laberinto + 40px de margen (20 arriba y abajo)
    parent: 'game', // El ID del div donde se renderizará el juego
    backgroundColor: '#000000', // Fondo negro, para que el contraste sea mejor con el laberinto azul
    scene: [MazeScene] // Las escenas que componen el juego
};

// Inicializa el juego con la configuración
const game = new Phaser.Game(config);