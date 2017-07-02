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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WPF_for_text_File_Statistic
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        private int numbOfWords = 43;
        private int numbOfSentences = 512;
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
                numbOfWordsText.Text = "Numb of words are " + numbOfWords.ToString();
                numbOfSentencesText.Text = "Numb of sentences are " + numbOfSentences.ToString();
            }
        }
    }
}
