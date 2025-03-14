<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        PictureBox1 = New PictureBox()
        PictureBox2 = New PictureBox()
        Moto = New RadioButton()
        Automovil = New RadioButton()
        Camion = New RadioButton()
        Trailer = New RadioButton()
        GroupBox1 = New GroupBox()
        Efectivo = New RadioButton()
        Credito = New RadioButton()
        GroupBox2 = New GroupBox()
        Residente = New RadioButton()
        De_paso = New RadioButton()
        GroupBox3 = New GroupBox()
        COBRO = New Button()
        Label1 = New Label()
        Label2 = New Label()
        Label3 = New Label()
        Label4 = New Label()
        Label5 = New Label()
        P_moto = New Label()
        P_camion = New Label()
        P_trailer = New Label()
        P_carro = New Label()
        Label10 = New Label()
        Label11 = New Label()
        Label12 = New Label()
        total = New Label()
        total_cr = New Label()
        total_e = New Label()
        CType(PictureBox1, ComponentModel.ISupportInitialize).BeginInit()
        CType(PictureBox2, ComponentModel.ISupportInitialize).BeginInit()
        GroupBox1.SuspendLayout()
        GroupBox2.SuspendLayout()
        GroupBox3.SuspendLayout()
        SuspendLayout()
        ' 
        ' PictureBox1
        ' 
        PictureBox1.Image = CType(resources.GetObject("PictureBox1.Image"), Image)
        PictureBox1.Location = New Point(12, 12)
        PictureBox1.Name = "PictureBox1"
        PictureBox1.Size = New Size(675, 169)
        PictureBox1.SizeMode = PictureBoxSizeMode.StretchImage
        PictureBox1.TabIndex = 0
        PictureBox1.TabStop = False
        ' 
        ' PictureBox2
        ' 
        PictureBox2.Image = CType(resources.GetObject("PictureBox2.Image"), Image)
        PictureBox2.Location = New Point(693, 12)
        PictureBox2.Name = "PictureBox2"
        PictureBox2.Size = New Size(224, 169)
        PictureBox2.SizeMode = PictureBoxSizeMode.StretchImage
        PictureBox2.TabIndex = 1
        PictureBox2.TabStop = False
        ' 
        ' Moto
        ' 
        Moto.AutoSize = True
        Moto.Font = New Font("Segoe UI", 14.25F)
        Moto.Location = New Point(20, 32)
        Moto.Name = "Moto"
        Moto.Size = New Size(75, 29)
        Moto.TabIndex = 2
        Moto.Text = "Moto"
        Moto.UseVisualStyleBackColor = True
        ' 
        ' Automovil
        ' 
        Automovil.AutoSize = True
        Automovil.Checked = True
        Automovil.Font = New Font("Segoe UI", 14.25F)
        Automovil.Location = New Point(146, 32)
        Automovil.Name = "Automovil"
        Automovil.Size = New Size(193, 29)
        Automovil.TabIndex = 3
        Automovil.TabStop = True
        Automovil.Text = "Automovil o Pickup"
        Automovil.UseVisualStyleBackColor = True
        ' 
        ' Camion
        ' 
        Camion.AutoSize = True
        Camion.Font = New Font("Segoe UI", 14.25F)
        Camion.Location = New Point(383, 32)
        Camion.Name = "Camion"
        Camion.Size = New Size(148, 29)
        Camion.TabIndex = 4
        Camion.Text = "Camion 2 Ejes"
        Camion.UseVisualStyleBackColor = True
        ' 
        ' Trailer
        ' 
        Trailer.AutoSize = True
        Trailer.Font = New Font("Segoe UI", 14.25F)
        Trailer.Location = New Point(566, 32)
        Trailer.Name = "Trailer"
        Trailer.Size = New Size(82, 29)
        Trailer.TabIndex = 5
        Trailer.Text = "Trailer"
        Trailer.UseVisualStyleBackColor = True
        ' 
        ' GroupBox1
        ' 
        GroupBox1.BackColor = Color.MistyRose
        GroupBox1.Controls.Add(Moto)
        GroupBox1.Controls.Add(Trailer)
        GroupBox1.Controls.Add(Automovil)
        GroupBox1.Controls.Add(Camion)
        GroupBox1.Font = New Font("Segoe UI", 14.25F, FontStyle.Regular, GraphicsUnit.Point, CByte(0))
        GroupBox1.Location = New Point(12, 187)
        GroupBox1.Name = "GroupBox1"
        GroupBox1.Size = New Size(677, 78)
        GroupBox1.TabIndex = 6
        GroupBox1.TabStop = False
        GroupBox1.Text = "SELECCIONA EL TIPO DE VEHICULO:"
        ' 
        ' Efectivo
        ' 
        Efectivo.AutoSize = True
        Efectivo.Checked = True
        Efectivo.Font = New Font("Segoe UI", 14.25F)
        Efectivo.Location = New Point(21, 32)
        Efectivo.Name = "Efectivo"
        Efectivo.Size = New Size(96, 29)
        Efectivo.TabIndex = 7
        Efectivo.TabStop = True
        Efectivo.Text = "Efectivo"
        Efectivo.UseVisualStyleBackColor = True
        ' 
        ' Credito
        ' 
        Credito.AutoSize = True
        Credito.Font = New Font("Segoe UI", 14.25F)
        Credito.Location = New Point(197, 33)
        Credito.Name = "Credito"
        Credito.Size = New Size(134, 29)
        Credito.TabIndex = 8
        Credito.Text = "Iave-Credito"
        Credito.UseVisualStyleBackColor = True
        ' 
        ' GroupBox2
        ' 
        GroupBox2.BackColor = Color.FromArgb(CByte(192), CByte(255), CByte(192))
        GroupBox2.Controls.Add(Credito)
        GroupBox2.Controls.Add(Efectivo)
        GroupBox2.Font = New Font("Segoe UI", 14.25F, FontStyle.Regular, GraphicsUnit.Point, CByte(0))
        GroupBox2.Location = New Point(12, 271)
        GroupBox2.Name = "GroupBox2"
        GroupBox2.Size = New Size(369, 68)
        GroupBox2.TabIndex = 9
        GroupBox2.TabStop = False
        GroupBox2.Text = "SELECCIONE EL TIPO DE PAGO:"
        ' 
        ' Residente
        ' 
        Residente.AutoSize = True
        Residente.Location = New Point(197, 32)
        Residente.Name = "Residente"
        Residente.Size = New Size(160, 29)
        Residente.TabIndex = 10
        Residente.Text = "Residente Local"
        Residente.UseVisualStyleBackColor = True
        ' 
        ' De_paso
        ' 
        De_paso.AutoSize = True
        De_paso.Checked = True
        De_paso.Location = New Point(21, 32)
        De_paso.Name = "De_paso"
        De_paso.Size = New Size(166, 29)
        De_paso.TabIndex = 11
        De_paso.TabStop = True
        De_paso.Text = "Usuario de paso"
        De_paso.UseVisualStyleBackColor = True
        ' 
        ' GroupBox3
        ' 
        GroupBox3.BackColor = Color.BlanchedAlmond
        GroupBox3.Controls.Add(De_paso)
        GroupBox3.Controls.Add(Residente)
        GroupBox3.Font = New Font("Segoe UI", 14.25F, FontStyle.Regular, GraphicsUnit.Point, CByte(0))
        GroupBox3.Location = New Point(12, 345)
        GroupBox3.Name = "GroupBox3"
        GroupBox3.Size = New Size(368, 78)
        GroupBox3.TabIndex = 12
        GroupBox3.TabStop = False
        GroupBox3.Text = "SELECCIONE EL TIPO DE USUARIO:"
        ' 
        ' COBRO
        ' 
        COBRO.BackColor = Color.FromArgb(CByte(255), CByte(128), CByte(128))
        COBRO.FlatAppearance.BorderColor = Color.Gold
        COBRO.FlatAppearance.BorderSize = 5
        COBRO.FlatAppearance.CheckedBackColor = Color.FromArgb(CByte(224), CByte(224), CByte(224))
        COBRO.FlatAppearance.MouseOverBackColor = Color.FromArgb(CByte(255), CByte(255), CByte(128))
        COBRO.FlatStyle = FlatStyle.Flat
        COBRO.Font = New Font("Segoe UI", 15.75F, FontStyle.Bold, GraphicsUnit.Point, CByte(0))
        COBRO.Location = New Point(578, 287)
        COBRO.Name = "COBRO"
        COBRO.Size = New Size(248, 119)
        COBRO.TabIndex = 13
        COBRO.Text = "---APLICAR COBRO---"
        COBRO.UseVisualStyleBackColor = False
        ' 
        ' Label1
        ' 
        Label1.AutoSize = True
        Label1.Font = New Font("Segoe UI", 14.25F)
        Label1.Location = New Point(158, 426)
        Label1.Name = "Label1"
        Label1.Size = New Size(89, 25)
        Label1.TabIndex = 14
        Label1.Text = "# PEAJES"
        Label1.TextAlign = ContentAlignment.TopCenter
        ' 
        ' Label2
        ' 
        Label2.AutoSize = True
        Label2.Font = New Font("Segoe UI", 14.25F)
        Label2.Location = New Point(25, 451)
        Label2.Name = "Label2"
        Label2.Size = New Size(128, 25)
        Label2.TabIndex = 15
        Label2.Text = "Motocicletas :"
        Label2.TextAlign = ContentAlignment.TopCenter
        ' 
        ' Label3
        ' 
        Label3.AutoSize = True
        Label3.Font = New Font("Segoe UI", 14.25F)
        Label3.Location = New Point(51, 480)
        Label3.Name = "Label3"
        Label3.Size = New Size(102, 25)
        Label3.TabIndex = 16
        Label3.Text = "Vehiculos :"
        Label3.TextAlign = ContentAlignment.TopCenter
        ' 
        ' Label4
        ' 
        Label4.AutoSize = True
        Label4.Font = New Font("Segoe UI", 14.25F)
        Label4.Location = New Point(48, 542)
        Label4.Name = "Label4"
        Label4.Size = New Size(104, 25)
        Label4.TabIndex = 17
        Label4.Text = "Camiones :"
        Label4.TextAlign = ContentAlignment.TopCenter
        ' 
        ' Label5
        ' 
        Label5.AutoSize = True
        Label5.Font = New Font("Segoe UI", 14.25F)
        Label5.Location = New Point(72, 512)
        Label5.Name = "Label5"
        Label5.Size = New Size(81, 25)
        Label5.TabIndex = 18
        Label5.Text = "Trailers :"
        Label5.TextAlign = ContentAlignment.TopCenter
        ' 
        ' P_moto
        ' 
        P_moto.AutoSize = True
        P_moto.Font = New Font("Segoe UI", 14.25F)
        P_moto.Location = New Point(158, 451)
        P_moto.Name = "P_moto"
        P_moto.Size = New Size(92, 25)
        P_moto.TabIndex = 19
        P_moto.Text = "__________"
        P_moto.TextAlign = ContentAlignment.TopCenter
        ' 
        ' P_camion
        ' 
        P_camion.AutoSize = True
        P_camion.Font = New Font("Segoe UI", 14.25F)
        P_camion.Location = New Point(158, 542)
        P_camion.Name = "P_camion"
        P_camion.Size = New Size(92, 25)
        P_camion.TabIndex = 20
        P_camion.Text = "__________"
        P_camion.TextAlign = ContentAlignment.TopCenter
        ' 
        ' P_trailer
        ' 
        P_trailer.AutoSize = True
        P_trailer.Font = New Font("Segoe UI", 14.25F)
        P_trailer.Location = New Point(158, 512)
        P_trailer.Name = "P_trailer"
        P_trailer.Size = New Size(92, 25)
        P_trailer.TabIndex = 21
        P_trailer.Text = "__________"
        P_trailer.TextAlign = ContentAlignment.TopCenter
        ' 
        ' P_carro
        ' 
        P_carro.AutoSize = True
        P_carro.Font = New Font("Segoe UI", 14.25F)
        P_carro.Location = New Point(158, 480)
        P_carro.Name = "P_carro"
        P_carro.Size = New Size(92, 25)
        P_carro.TabIndex = 22
        P_carro.Text = "__________"
        P_carro.TextAlign = ContentAlignment.TopCenter
        ' 
        ' Label10
        ' 
        Label10.AutoSize = True
        Label10.Font = New Font("Segoe UI", 14.25F, FontStyle.Bold)
        Label10.Location = New Point(502, 453)
        Label10.Name = "Label10"
        Label10.Size = New Size(238, 25)
        Label10.TabIndex = 23
        Label10.Text = "TOTAL COBRO EFECTIVO :"
        Label10.TextAlign = ContentAlignment.TopCenter
        ' 
        ' Label11
        ' 
        Label11.AutoSize = True
        Label11.Font = New Font("Segoe UI", 14.25F, FontStyle.Bold)
        Label11.Location = New Point(502, 496)
        Label11.Name = "Label11"
        Label11.Size = New Size(279, 25)
        Label11.TabIndex = 24
        Label11.Text = "TOTAL COBRO IAVE-CREDITO :"
        Label11.TextAlign = ContentAlignment.MiddleCenter
        ' 
        ' Label12
        ' 
        Label12.AutoSize = True
        Label12.Font = New Font("Segoe UI", 14.25F, FontStyle.Bold)
        Label12.Location = New Point(502, 538)
        Label12.Name = "Label12"
        Label12.Size = New Size(235, 25)
        Label12.TabIndex = 25
        Label12.Text = "SUMA TOTAL COBRADO :"
        Label12.TextAlign = ContentAlignment.TopCenter
        ' 
        ' total
        ' 
        total.AutoSize = True
        total.Font = New Font("Segoe UI", 14.25F)
        total.Location = New Point(787, 544)
        total.Name = "total"
        total.Size = New Size(92, 25)
        total.TabIndex = 26
        total.Text = "__________"
        total.TextAlign = ContentAlignment.TopCenter
        ' 
        ' total_cr
        ' 
        total_cr.AutoSize = True
        total_cr.Font = New Font("Segoe UI", 14.25F)
        total_cr.Location = New Point(787, 496)
        total_cr.Name = "total_cr"
        total_cr.Size = New Size(92, 25)
        total_cr.TabIndex = 27
        total_cr.Text = "__________"
        ' 
        ' total_e
        ' 
        total_e.AutoSize = True
        total_e.Font = New Font("Segoe UI", 14.25F)
        total_e.Location = New Point(787, 453)
        total_e.Name = "total_e"
        total_e.Size = New Size(92, 25)
        total_e.TabIndex = 28
        total_e.Text = "__________"
        total_e.TextAlign = ContentAlignment.TopCenter
        ' 
        ' Form1
        ' 
        AccessibleName = "CASETA DE COBRO"
        AutoScaleDimensions = New SizeF(7F, 15F)
        AutoScaleMode = AutoScaleMode.Font
        ClientSize = New Size(929, 593)
        Controls.Add(total_e)
        Controls.Add(total_cr)
        Controls.Add(total)
        Controls.Add(Label12)
        Controls.Add(Label11)
        Controls.Add(Label10)
        Controls.Add(P_carro)
        Controls.Add(P_trailer)
        Controls.Add(P_camion)
        Controls.Add(P_moto)
        Controls.Add(Label5)
        Controls.Add(Label4)
        Controls.Add(Label3)
        Controls.Add(Label2)
        Controls.Add(Label1)
        Controls.Add(COBRO)
        Controls.Add(GroupBox3)
        Controls.Add(GroupBox2)
        Controls.Add(GroupBox1)
        Controls.Add(PictureBox2)
        Controls.Add(PictureBox1)
        Name = "Form1"
        Text = "CASETA DE COBRO"
        CType(PictureBox1, ComponentModel.ISupportInitialize).EndInit()
        CType(PictureBox2, ComponentModel.ISupportInitialize).EndInit()
        GroupBox1.ResumeLayout(False)
        GroupBox1.PerformLayout()
        GroupBox2.ResumeLayout(False)
        GroupBox2.PerformLayout()
        GroupBox3.ResumeLayout(False)
        GroupBox3.PerformLayout()
        ResumeLayout(False)
        PerformLayout()
    End Sub

    Friend WithEvents PictureBox1 As PictureBox
    Friend WithEvents PictureBox2 As PictureBox
    Friend WithEvents Moto As RadioButton
    Friend WithEvents Automovil As RadioButton
    Friend WithEvents Camion As RadioButton
    Friend WithEvents Trailer As RadioButton
    Friend WithEvents GroupBox1 As GroupBox
    Friend WithEvents Efectivo As RadioButton
    Friend WithEvents Credito As RadioButton
    Friend WithEvents GroupBox2 As GroupBox
    Friend WithEvents Residente As RadioButton
    Friend WithEvents De_paso As RadioButton
    Friend WithEvents GroupBox3 As GroupBox
    Friend WithEvents COBRO As Button
    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label4 As Label
    Friend WithEvents Label5 As Label
    Friend WithEvents P_moto As Label
    Friend WithEvents P_camion As Label
    Friend WithEvents P_trailer As Label
    Friend WithEvents P_carro As Label
    Friend WithEvents Label10 As Label
    Friend WithEvents Label11 As Label
    Friend WithEvents Label12 As Label
    Friend WithEvents total As Label
    Friend WithEvents total_cr As Label
    Friend WithEvents total_e As Label

End Class
