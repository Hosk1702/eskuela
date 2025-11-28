namespace serpiente
{
    partial class Snake
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            caja = new PictureBox();
            gametimer = new System.Windows.Forms.Timer(components);
            lblScoreTitle = new Label();
            lblScoreValue = new Label();
            lblTrapTitle = new Label();
            lblTrapCountValue = new Label();
            lblLevelTitle = new Label();
            lblLevelValue = new Label();
            lblLeaderboardTitle = new Label();
            lblLeaderboardValue = new Label();
            ((System.ComponentModel.ISupportInitialize)caja).BeginInit();
            SuspendLayout();
            // 
            // caja
            // 
            caja.BackColor = Color.FromArgb(192, 255, 192);
            caja.Location = new Point(0, 100);
            caja.Name = "caja";
            caja.Size = new Size(1258, 664);
            caja.TabIndex = 0;
            caja.TabStop = false;
            caja.Paint += caja_Paint;
            // 
            // gametimer
            // 
            gametimer.Tick += gametimer_Tick;
            // 
            // lblScoreTitle
            // 
            lblScoreTitle.AutoSize = true;
            lblScoreTitle.Font = new Font("Segoe UI", 10F, FontStyle.Bold);
            lblScoreTitle.Location = new Point(12, 9);
            lblScoreTitle.Name = "lblScoreTitle";
            lblScoreTitle.Size = new Size(121, 28);
            lblScoreTitle.TabIndex = 1;
            lblScoreTitle.Text = "Puntuación:";
            // 
            // lblScoreValue
            // 
            lblScoreValue.AutoSize = true;
            lblScoreValue.Font = new Font("Segoe UI", 10F, FontStyle.Bold);
            lblScoreValue.Location = new Point(140, 9);
            lblScoreValue.Name = "lblScoreValue";
            lblScoreValue.Size = new Size(24, 28);
            lblScoreValue.TabIndex = 2;
            lblScoreValue.Text = "0";
            // 
            // lblTrapTitle
            // 
            lblTrapTitle.AutoSize = true;
            lblTrapTitle.Font = new Font("Segoe UI", 10F, FontStyle.Bold);
            lblTrapTitle.Location = new Point(12, 37);
            lblTrapTitle.Name = "lblTrapTitle";
            lblTrapTitle.Size = new Size(92, 28);
            lblTrapTitle.TabIndex = 3;
            lblTrapTitle.Text = "Bombas:";
            // 
            // lblTrapCountValue
            // 
            lblTrapCountValue.AutoSize = true;
            lblTrapCountValue.Font = new Font("Segoe UI", 10F, FontStyle.Bold);
            lblTrapCountValue.Location = new Point(140, 37);
            lblTrapCountValue.Name = "lblTrapCountValue";
            lblTrapCountValue.Size = new Size(57, 28);
            lblTrapCountValue.TabIndex = 4;
            lblTrapCountValue.Text = "0 / 3";
            // 
            // lblLevelTitle
            // 
            lblLevelTitle.AutoSize = true;
            lblLevelTitle.Font = new Font("Segoe UI", 10F, FontStyle.Bold);
            lblLevelTitle.Location = new Point(12, 65);
            lblLevelTitle.Name = "lblLevelTitle";
            lblLevelTitle.Size = new Size(66, 28);
            lblLevelTitle.TabIndex = 5;
            lblLevelTitle.Text = "Nivel:";
            // 
            // lblLevelValue
            // 
            lblLevelValue.AutoSize = true;
            lblLevelValue.Font = new Font("Segoe UI", 10F, FontStyle.Bold);
            lblLevelValue.Location = new Point(140, 65);
            lblLevelValue.Name = "lblLevelValue";
            lblLevelValue.Size = new Size(24, 28);
            lblLevelValue.TabIndex = 6;
            lblLevelValue.Text = "1";
            // 
            // lblLeaderboardTitle
            // 
            lblLeaderboardTitle.AutoSize = true;
            lblLeaderboardTitle.Font = new Font("Segoe UI", 10F, FontStyle.Bold);
            lblLeaderboardTitle.Location = new Point(900, 9);
            lblLeaderboardTitle.Name = "lblLeaderboardTitle";
            lblLeaderboardTitle.Size = new Size(224, 28);
            lblLeaderboardTitle.TabIndex = 7;
            lblLeaderboardTitle.Text = "Mejores Puntuaciones:";
            // 
            // lblLeaderboardValue
            // 
            lblLeaderboardValue.AutoSize = true;
            lblLeaderboardValue.Font = new Font("Segoe UI", 10F);
            lblLeaderboardValue.Location = new Point(900, 37);
            lblLeaderboardValue.Name = "lblLeaderboardValue";
            lblLeaderboardValue.Size = new Size(116, 28);
            lblLeaderboardValue.TabIndex = 8;
            lblLeaderboardValue.Text = "(cargando...)";
            // 
            // Snake
            // 
            AutoScaleDimensions = new SizeF(10F, 25F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1258, 764);
            Controls.Add(lblLeaderboardValue);
            Controls.Add(lblLeaderboardTitle);
            Controls.Add(lblLevelValue);
            Controls.Add(lblLevelTitle);
            Controls.Add(lblTrapCountValue);
            Controls.Add(lblTrapTitle);
            Controls.Add(lblScoreValue);
            Controls.Add(lblScoreTitle);
            Controls.Add(caja);
            Name = "Snake";
            Text = "Snake";
            KeyDown += Snake_KeyDown;
            ((System.ComponentModel.ISupportInitialize)caja).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private PictureBox caja;
        private System.Windows.Forms.Timer gametimer;
        private Label lblScoreTitle;
        private Label lblScoreValue;
        private Label lblTrapTitle;
        private Label lblTrapCountValue;
        private Label lblLevelTitle;
        private Label lblLevelValue;
        private Label lblLeaderboardTitle;
        private Label lblLeaderboardValue;
    }
}