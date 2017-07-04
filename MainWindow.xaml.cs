using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Runtime.InteropServices;


namespace WPF_for_text_File_Statistic
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        private int numbOfWords;
        private int numbOfSentences;
        //private String nameOfFile;
        // private String textString;


        [System.Runtime.InteropServices.DllImport("C:\\Users\\kutko\\Documents\\Visual Studio 2015\\Projects\\Dll For Text File Statistic\\Debug\\Dll For Text File Statistic.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        //   [DllImport("C:\\Users\\kutko\\Documents\\Visual Studio 2015\\Projects\\Dll For Text File Statistic\\Debug\\Dll For Text File Statistic.dll")]
        public static extern void getStatistic([MarshalAs(UnmanagedType.LPStr)]  string nameOfFile, ref int numbOfWords, ref int numbOfSentences);

        [System.Runtime.InteropServices.DllImport("C:\\Users\\kutko\\Documents\\Visual Studio 2015\\Projects\\TestDllOnC++\\Debug\\TestDllOnC++.dll", CharSet = CharSet.Unicode)]

        public static extern int mull(int a, int b);
        public MainWindow()
        {
            InitializeComponent();
        }

        private void showButtonClick(object sender, RoutedEventArgs e)
        {
            if(nameOfFile.Text == string.Empty)
            {
                MessageBox.Show("you did't input name of file");
            }
            else
            {
                StringBuilder tempStringNameofFile = new StringBuilder(40);
                tempStringNameofFile.Insert(0, "Data.txt");
                //tempStringNameofFile.Insert(0, nameOfFile.Text);
                getStatistic(nameOfFile.Text, ref numbOfWords, ref numbOfSentences);

                numbOfWordsText.Text = "Numb of words are " + numbOfWords.ToString() ;
                numbOfSentencesText.Text = "Numb of sentences are " + numbOfSentences.ToString();            }
        }
    }
}
