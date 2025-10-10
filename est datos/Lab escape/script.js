const canvas = document.getElementById('mazeCanvas');
const ctx = canvas.getContext('2d');

ctx.imageSmoothingEnabled = false;

// --- AJUSTES DE TAMAÑO ---
const mazeWidth = 500;
const mazeHeight = 500;
const cellSize = 20;
const cols = Math.floor(mazeWidth / cellSize);
const rows = Math.floor(mazeHeight / cellSize);

canvas.width = mazeWidth;
canvas.height = mazeHeight;

// --- OBJETO DEL JUGADOR ---
const player = {
    x: 0, // Posición en la cuadrícula (columna)
    y: 0, // Posición en la cuadrícula (fila)
    sprite: new Image(),
    size: cellSize * 0.8
};
player.sprite.src = 'player.png';


// --- LÓGICA DEL LABERINTO ---
const grid = [];
class Cell {
    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.walls = { top: true, right: true, bottom: true, left: true };
        this.visited = false;
    }
}

for (let y = 0; y < rows; y++) {
    grid.push(Array.from({ length: cols }, (_, x) => new Cell(x, y)));
}

function generateMaze() {
    const stack = [];
    let current = grid[0][0];
    current.visited = true;
    let unvisited = rows * cols - 1;

    while (unvisited > 0) {
        const neighbors = getUnvisitedNeighbors(current);
        if (neighbors.length > 0) {
            const next = neighbors[Math.floor(Math.random() * neighbors.length)];
            stack.push(current);
            removeWalls(current, next);
            current = next;
            current.visited = true;
            unvisited--;
        } else if (stack.length > 0) {
            current = stack.pop();
        }
    }
}

function getUnvisitedNeighbors(cell) {
    const neighbors = [];
    const { x, y } = cell;

    // Vecino de arriba
    if (y > 0 && !grid[y - 1][x].visited) {
        neighbors.push(grid[y - 1][x]);
    }
    // Vecino de la derecha
    if (x < cols - 1 && !grid[y][x + 1].visited) {
        neighbors.push(grid[y][x + 1]);
    }
    // Vecino de abajo
    if (y < rows - 1 && !grid[y + 1][x].visited) {
        neighbors.push(grid[y + 1][x]);
    }
    // Vecino de la izquierda
    if (x > 0 && !grid[y][x - 1].visited) {
        neighbors.push(grid[y][x - 1]);
    }
    return neighbors;
}

function removeWalls(a, b) {
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

// --- FUNCIONES DE DIBUJO ---
function redraw() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    drawMaze();
    drawPlayer();
}

function drawMaze() {
    for (const row of grid) {
        for (const cell of row) {
            drawCell(cell);
        }
    }
}

function drawCell(cell) {
    const x = cell.x * cellSize;
    const y = cell.y * cellSize;
    ctx.strokeStyle = 'black';
    ctx.lineWidth = 2;

    if (cell.walls.top) {
        ctx.beginPath();
        ctx.moveTo(x, y);
        ctx.lineTo(x + cellSize, y);
        ctx.stroke();
    }
    if (cell.walls.right) {
        ctx.beginPath();
        ctx.moveTo(x + cellSize, y);
        ctx.lineTo(x + cellSize, y + cellSize);
        ctx.stroke();
    }
    if (cell.walls.bottom) {
        ctx.beginPath();
        ctx.moveTo(x + cellSize, y + cellSize);
        ctx.lineTo(x, y + cellSize);
        ctx.stroke();
    }
    if (cell.walls.left) {
        ctx.beginPath();
        ctx.moveTo(x, y + cellSize);
        ctx.lineTo(x, y);
        ctx.stroke();
    }
}

function drawPlayer() {
    const pixelX = player.x * cellSize + (cellSize - player.size) / 2;
    const pixelY = player.y * cellSize + (cellSize - player.size) / 2;
    ctx.drawImage(player.sprite, pixelX, pixelY, player.size, player.size);
}

// --- LÓGICA DE MOVIMIENTO ---
window.addEventListener('keydown', (e) => {
    const currentCell = grid[player.y][player.x];

    switch (e.key) {
        case 'ArrowUp':
            if (!currentCell.walls.top) {
                player.y--;
            }
            break;
        case 'ArrowDown':
            if (!currentCell.walls.bottom) {
                player.y++;
            }
            break;
        case 'ArrowLeft':
            if (!currentCell.walls.left) {
                player.x--;
            }
            break;
        case 'ArrowRight':
            if (!currentCell.walls.right) {
                player.x++;
            }
            break;
    }
    redraw(); // Vuelve a dibujar todo después de un movimiento
});


// --- INICIO DEL JUEGO ---
player.sprite.onload = () => {
    generateMaze();
    redraw();
};