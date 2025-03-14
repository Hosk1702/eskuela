Imports System.Runtime.InteropServices

Public Class Form1
    Dim Ac_moto_r, Ac_auto_r, Ac_camion_r, Ac_trailer_r, Ac_moto_dp, Ac_auto_dp, Ac_camion_dp, Ac_trailer_dp, C_cr, C_e As Single

    Private Sub COBRO_Click(sender As Object, e As EventArgs) Handles COBRO.Click
        Dim importe_total, importe_cr, importe_e As Single

        If De_paso.Checked Then
            If Efectivo.Checked Then
                Select Case True
                    Case Moto.Checked
                        importe_e = 40
                        Ac_moto_dp = Ac_moto_dp + 1
                    Case Automovil.Checked
                        importe_e = 80
                        Ac_auto_dp = Ac_auto_dp + 1
                    Case Camion.Checked
                        importe_e = 100
                        Ac_camion_dp = Ac_camion_dp + 1
                    Case Trailer.Checked
                        importe_e = 150
                        Ac_trailer_dp = Ac_trailer_dp + 1
                End Select
            Else
                Select Case True
                    Case Moto.Checked
                        importe_cr = 40
                        Ac_moto_dp = Ac_moto_dp + 1
                    Case Automovil.Checked
                        importe_cr = 80
                        Ac_auto_dp = Ac_auto_dp + 1
                    Case Camion.Checked
                        importe_cr = 100
                        Ac_camion_dp = Ac_camion_dp + 1
                    Case Trailer.Checked
                        importe_cr = 150
                        Ac_trailer_dp = Ac_trailer_dp + 1
                End Select
            End If
        Else
            If Efectivo.Checked Then
                Select Case True
                    Case Moto.Checked
                        importe_e = 5
                        Ac_moto_r = Ac_moto_r + 1
                    Case Automovil.Checked
                        importe_e = 10
                        Ac_auto_r = Ac_auto_r + 1
                    Case Camion.Checked
                        importe_e = 15
                        Ac_camion_r = Ac_camion_r + 1
                    Case Trailer.Checked
                        importe_e = 30
                        Ac_trailer_r = Ac_trailer_r + 1
                End Select
            Else
                Select Case True
                    Case Moto.Checked
                        importe_cr = 5
                        Ac_moto_r = Ac_moto_r + 1
                    Case Automovil.Checked
                        importe_cr = 10
                        Ac_auto_r = Ac_auto_r + 1
                    Case Camion.Checked
                        importe_cr = 15
                        Ac_camion_r = Ac_camion_r + 1
                    Case Trailer.Checked
                        importe_cr = 30
                        Ac_trailer_r = Ac_trailer_r + 1
                End Select
            End If
        End If

        C_cr = C_cr + importe_cr
        C_e = C_e + importe_e
        importe_total = C_cr + C_e

        P_moto.Text = Ac_moto_dp + Ac_moto_r
        P_carro.Text = Ac_auto_dp + Ac_auto_r
        P_camion.Text = Ac_camion_dp + Ac_camion_r
        P_trailer.Text = Ac_trailer_dp + Ac_trailer_r


        total_cr.Text = C_cr
        total_e.Text = C_e
        total.Text = importe_total
    End Sub
End Class
