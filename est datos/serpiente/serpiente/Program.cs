namespace serpiente
{
    internal static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            // To customize application configuration such as set high DPI settings or default font,
            // see https://aka.ms/applicationconfiguration.
            ApplicationConfiguration.Initialize();
            // CORREGIDO: Aquí llamamos a 'Snake' en lugar de 'Form1'
            Application.Run(new Snake());
        }
    }
}