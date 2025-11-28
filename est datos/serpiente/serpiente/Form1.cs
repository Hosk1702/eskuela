using Microsoft.VisualBasic;
using System.Text;
using System.IO;
using System.Linq;

namespace serpiente
{
    public partial class Snake : Form
    {
        private Listas snake = new Listas();
        private int cuadrado = 20;
        private string direccion = "derecha";
        private string siguiente_direccion = "derecha";
        private bool perder = false;

        private int score = 0;
        private List<int> highScores = new List<int>();
        private const string LEADERBOARD_FILE = "leaderboard.txt";

        // Variables de Juego (Niveles, Trampas, Manzanas)
        private List<Point> traps = new List<Point>();
        private List<Point> foods = new List<Point>();
        private const int APPLE_COUNT_ON_SCREEN = 3;
        private int trapCount = 0;
        private bool invincible = false;

        private int level = 1;
        private int appleCount = 0;
        private const int APPLES_PER_LEVEL = 15;
        private const int LEVEL_UP_BONUS = 50;
        private const int BASE_SPEED_MS = 100;

        // Imágenes
        private Image imgManzana;
        private Image imgCabezaArriba;
        private Image imgCabezaAbajo;
        private Image imgCabezaIzquierda;
        private Image imgCabezaDerecha;
        private Image imgColaArriba;
        private Image imgColaAbajo;
        private Image imgColaIzquierda;
        private Image imgColaDerecha;
        private Image imgCuerpoVertical;
        private Image imgCuerpoHorizontal;
        private Image imgEsquinaSupIzquierda;
        private Image imgEsquinaSupDerecha;
        private Image imgEsquinaInfIzquierda;
        private Image imgEsquinaInfDerecha;

        public Snake()
        {
            InitializeComponent();

            // Cargar Imágenes
            imgManzana = Image.FromFile("assets/apple.png");
            imgCabezaArriba = Image.FromFile("assets/head_up.png");
            imgCabezaAbajo = Image.FromFile("assets/head_down.png");
            imgCabezaIzquierda = Image.FromFile("assets/head_left.png");
            imgCabezaDerecha = Image.FromFile("assets/head_right.png");
            imgColaArriba = Image.FromFile("assets/tail_up.png");
            imgColaAbajo = Image.FromFile("assets/tail_down.png");
            imgColaIzquierda = Image.FromFile("assets/tail_left.png");
            imgColaDerecha = Image.FromFile("assets/tail_right.png");
            imgCuerpoVertical = Image.FromFile("assets/body_vertical.png");
            imgCuerpoHorizontal = Image.FromFile("assets/body_horizontal.png");
            imgEsquinaSupIzquierda = Image.FromFile("assets/body_topleft.png");
            imgEsquinaSupDerecha = Image.FromFile("assets/body_topright.png");
            imgEsquinaInfIzquierda = Image.FromFile("assets/body_bottomleft.png");
            imgEsquinaInfDerecha = Image.FromFile("assets/body_bottomright.png");

            LoadLeaderboard();
            UpdateLeaderboardLabel();

            startgame();
        }

        private void gametimer_Tick(object sender, EventArgs e)
        {
            if (perder) return;

            direccion = siguiente_direccion;
            Point newHead = snake.head.data;

            switch (direccion)
            {
                case "derecha": newHead.X += cuadrado; break;
                case "izquierda": newHead.X -= cuadrado; break;
                case "arriba": newHead.Y -= cuadrado; break;
                case "abajo": newHead.Y += cuadrado; break;
            }

            // Warp (Teletransporte en bordes)
            int gridWidth = caja.Width / cuadrado;
            int gridHeight = caja.Height / cuadrado;
            int maxX = (gridWidth - 1) * cuadrado;
            int maxY = (gridHeight - 1) * cuadrado;

            if (newHead.X < 0) newHead.X = maxX;
            else if (newHead.X > maxX) newHead.X = 0;
            else if (newHead.Y < 0) newHead.Y = maxY;
            else if (newHead.Y > maxY) newHead.Y = 0;

            snake.begininsert(newHead);

            // Auto-colisión
            if (!invincible)
            {
                Nodo? actseg = snake.head.siguiente;
                while (actseg != null)
                {
                    if (newHead == actseg.data)
                    {
                        perdiste();
                        return;
                    }
                    actseg = actseg.siguiente;
                }
            }

            // Colisión con Objetos
            Point? foodHit = null;
            foreach (Point f in foods)
            {
                if (newHead == f) { foodHit = f; break; }
            }

            Point? trapHit = null;
            foreach (Point t in traps)
            {
                if (newHead == t) { trapHit = t; break; }
            }

            if (foodHit.HasValue) // Comió manzana
            {
                score += 10;
                appleCount++;
                UpdateScoreLabel();

                if (appleCount >= APPLES_PER_LEVEL)
                {
                    LevelUp();
                }

                foods.Remove(foodHit.Value);
                GenerarNuevaComida();
            }
            else if (trapHit.HasValue) // Tocó bomba
            {
                score -= 10;
                if (score < 0) score = 0;
                UpdateScoreLabel();

                if (snake.Length() > 3)
                {
                    snake.last_delete();
                }

                trapCount++;
                UpdateTrapLabel();

                if (trapCount >= 3)
                {
                    perdiste();
                    return;
                }

                traps.Remove(trapHit.Value);
                GenerarNuevaTrampa();
            }
            else
            {
                snake.last_delete();
            }

            caja.Invalidate();
        }

        private void caja_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Nodo? puntero = snake.head;
            Nodo? previo = null;

            // Dibujar Serpiente
            while (puntero != null)
            {
                Image imgSnake;
                Nodo? siguiente = puntero.siguiente;

                if (previo == null) // Cabeza
                {
                    switch (direccion)
                    {
                        case "derecha": imgSnake = imgCabezaDerecha; break;
                        case "izquierda": imgSnake = imgCabezaIzquierda; break;
                        case "arriba": imgSnake = imgCabezaArriba; break;
                        default: imgSnake = imgCabezaAbajo; break;
                    }
                }
                else if (siguiente == null) // Cola
                {
                    Point posPrevia = previo.data;
                    Point posCola = puntero.data;

                    // La cola apunta en la dirección del cuerpo previo
                    if (posPrevia.X < posCola.X) imgSnake = imgColaDerecha;
                    else if (posPrevia.X > posCola.X) imgSnake = imgColaIzquierda;
                    else if (posPrevia.Y < posCola.Y) imgSnake = imgColaAbajo;
                    else imgSnake = imgColaArriba;
                }
                else // Cuerpo
                {
                    Point posPrevia = previo.data;
                    Point posActual = puntero.data;
                    Point posSiguiente = siguiente.data;

                    if (posPrevia.X == posSiguiente.X) imgSnake = imgCuerpoVertical;
                    else if (posPrevia.Y == posSiguiente.Y) imgSnake = imgCuerpoHorizontal;
                    else
                    {
                        // Esquinas
                        if ((posPrevia.Y < posActual.Y && posSiguiente.X < posActual.X) || (posPrevia.X < posActual.X && posSiguiente.Y < posActual.Y))
                            imgSnake = imgEsquinaSupIzquierda;
                        else if ((posPrevia.Y < posActual.Y && posSiguiente.X > posActual.X) || (posPrevia.X > posActual.X && posSiguiente.Y < posActual.Y))
                            imgSnake = imgEsquinaSupDerecha;
                        else if ((posPrevia.Y > posActual.Y && posSiguiente.X < posActual.X) || (posPrevia.X < posActual.X && posSiguiente.Y > posActual.Y))
                            imgSnake = imgEsquinaInfIzquierda;
                        else
                            imgSnake = imgEsquinaInfDerecha;
                    }
                }

                g.DrawImage(imgSnake, puntero.data.X, puntero.data.Y, cuadrado, cuadrado);
                previo = puntero;
                puntero = puntero.siguiente;
            }

            // Dibujar Manzanas
            foreach (Point f in foods)
            {
                g.DrawImage(imgManzana, f.X, f.Y, cuadrado, cuadrado);
            }

            // Dibujar Trampas
            foreach (Point t in traps)
            {
                g.DrawString("💣", new Font("Segoe UI Emoji", 12), Brushes.Black, t.X, t.Y);
            }
        }

        private void Snake_KeyDown(object sender, KeyEventArgs e)
        {
            Keys key = e.KeyCode;

            if (key == Keys.Right && direccion != "izquierda") siguiente_direccion = "derecha";
            else if (key == Keys.Left && direccion != "derecha") siguiente_direccion = "izquierda";
            else if (key == Keys.Up && direccion != "abajo") siguiente_direccion = "arriba";
            else if (key == Keys.Down && direccion != "arriba") siguiente_direccion = "abajo";

            // Trucos
            else if (key == Keys.I) invincible = !invincible;
            else if (key == Keys.P) { score += 100; UpdateScoreLabel(); }
        }

        private void startgame()
        {
            perder = false;
            score = 0;
            trapCount = 0;
            level = 1;
            appleCount = 0;

            UpdateScoreLabel();
            UpdateTrapLabel();
            UpdateLevelLabel();

            invincible = false;
            gametimer.Interval = BASE_SPEED_MS;

            direccion = "derecha";
            siguiente_direccion = "derecha";
            snake = new Listas();
            snake.begininsert(new Point(60, 100));
            snake.begininsert(new Point(80, 100));
            snake.begininsert(new Point(100, 100));

            // Generación inicial
            foods.Clear();
            traps.Clear();

            for (int i = 0; i < APPLE_COUNT_ON_SCREEN; i++) GenerarNuevaComida();
            GenerarNuevaTrampa();

            gametimer.Start();
        }

        private Point GetRandomEmptyPoint()
        {
            Random rnd = new Random();
            int x = caja.Width / cuadrado;
            int y = caja.Height / cuadrado;
            Point p;

            while (true)
            {
                p = new Point(rnd.Next(0, x) * cuadrado, rnd.Next(0, y) * cuadrado);

                // Evitar serpiente
                bool onSnake = false;
                Nodo? temp = snake.head;
                while (temp != null)
                {
                    if (p == temp.data) { onSnake = true; break; }
                    temp = temp.siguiente;
                }
                if (onSnake) continue;

                // Evitar otras comidas y trampas
                if (foods.Contains(p)) continue;
                if (traps.Contains(p)) continue;

                return p;
            }
        }

        private void GenerarNuevaComida()
        {
            foods.Add(GetRandomEmptyPoint());
        }

        private void GenerarNuevaTrampa()
        {
            traps.Add(GetRandomEmptyPoint());
        }

        private void perdiste()
        {
            perder = true;
            gametimer.Stop();

            CheckHighScore();
            UpdateLeaderboardLabel();

            string message = (trapCount >= 3)
                ? $"¡Demasiadas bombas! Perdiste.\nPuntuación final: {score}"
                : $"¡Perdiste! Tu puntuación: {score}";

            MessageBox.Show(message);

            startgame();
        }

        private void UpdateScoreLabel() { lblScoreValue.Text = score.ToString(); }
        private void UpdateTrapLabel() { lblTrapCountValue.Text = $"{trapCount} / 3"; }
        private void UpdateLevelLabel() { lblLevelValue.Text = level.ToString(); }

        private void LevelUp()
        {
            level++;
            appleCount = 0;
            score += LEVEL_UP_BONUS;

            UpdateScoreLabel();
            UpdateLevelLabel();

            // Aumentar velocidad (mínimo 40ms)
            gametimer.Interval = Math.Max(40, BASE_SPEED_MS - (level * 5));

            // Añadir trampa extra
            GenerarNuevaTrampa();
        }

        private void LoadLeaderboard()
        {
            if (!File.Exists(LEADERBOARD_FILE)) return;

            highScores.Clear();
            var lines = File.ReadAllLines(LEADERBOARD_FILE);
            foreach (var line in lines)
            {
                if (int.TryParse(line, out int scoreFromFile)) highScores.Add(scoreFromFile);
            }
            SortHighScores();
        }

        private void CheckHighScore()
        {
            highScores.Add(score);
            SortHighScores();
            if (highScores.Count > 5) highScores = highScores.Take(5).ToList();
            SaveLeaderboard();
        }

        private void SaveLeaderboard()
        {
            var lines = highScores.Select(s => s.ToString()).ToList();
            File.WriteAllLines(LEADERBOARD_FILE, lines);
        }

        private void SortHighScores()
        {
            highScores = highScores.OrderByDescending(s => s).ToList();
        }

        private void UpdateLeaderboardLabel()
        {
            StringBuilder sb = new StringBuilder();
            int count = Math.Min(highScores.Count, 5);

            if (count == 0) sb.AppendLine(" (vacío)");
            else
            {
                for (int i = 0; i < count; i++) sb.AppendLine($"{(i + 1)}. {highScores[i]}");
            }
            lblLeaderboardValue.Text = sb.ToString();
        }
    }

    public class Nodo
    {
        public Point data;
        public Nodo? siguiente;
        public Nodo(Point d) { data = d; siguiente = null; }
    }

    public class Listas
    {
        public Nodo? head;
        public Listas() { head = null; }

        public int Length()
        {
            int count = 0;
            Nodo? temp = head;
            while (temp != null) { count++; temp = temp.siguiente; }
            return count;
        }

        public void begininsert(Point item)
        {
            Nodo puntero = new Nodo(item);
            puntero.siguiente = head;
            head = puntero;
        }
        public void lastinsert(Point item)
        {
            Nodo puntero = new Nodo(item);
            if (head == null) { head = puntero; }
            else
            {
                Nodo temp = head;
                while (temp.siguiente != null) { temp = temp.siguiente; }
                temp.siguiente = puntero;
            }
        }
        public void last_delete()
        {
            if (head == null) { return; }
            else if (head.siguiente == null) { head = null; }
            else
            {
                Nodo temp = head;
                while (temp.siguiente.siguiente != null) { temp = temp.siguiente; }
                temp.siguiente = null;
            }
        }
    }
}