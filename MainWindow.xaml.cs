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
using System.Collections.Generic;


namespace WPF_for_text_File_Statistic
{
    public partial class MainWindow : Window
    {

        private int numbOfWords;
        private int numbOfSentences;

        [System.Runtime.InteropServices.DllImport("C:\\Users\\kutko\\Documents\\Visual Studio 2015\\Projects\\Dll For Text File Statistic\\Debug\\Dll For Text File Statistic.dll", CharSet = CharSet.Unicode, CallingConvention = CallingConvention.Cdecl)]
        public static extern void getStatistic([MarshalAs(UnmanagedType.LPStr)]  string nameOfFile, ref int numbOfWords, ref int numbOfSentences);

        public MainWindow()
        {
            InitializeComponent();
           
        }

        private void showButtonClick(object sender, RoutedEventArgs e)
        {
            if (nameOfFile.Text == string.Empty)
            {
                MessageBox.Show("you did't input name of file");
            }
            else
            {
                getStatistic(nameOfFile.Text, ref numbOfWords, ref numbOfSentences);
                numbOfWordsText.Text = "Numb of words are " + numbOfWords.ToString();
                numbOfSentencesText.Text = "Numb of sentences are " + numbOfSentences.ToString();
                List < StatisticOfUniqueWords > statisticListItems = new List<StatisticOfUniqueWords>();
                statisticListItems.Add(new StatisticOfUniqueWords() { uniqueWord = "cat", numbOfWordsInText = 42, shareOfWordsInText = 2 });
                statisticListItems.Add(new StatisticOfUniqueWords() { uniqueWord = "dog", numbOfWordsInText = 39, shareOfWordsInText = 14 });
                statisticListItems.Add(new StatisticOfUniqueWords() { uniqueWord = "row", numbOfWordsInText = 13, shareOfWordsInText = 66 });
                statisticList.ItemsSource = statisticListItems; 
            }
        }
    }

    public class StatisticOfUniqueWords
    {
        public string uniqueWord { get; set; }
        public int numbOfWordsInText { get; set; }
        public int shareOfWordsInText { get; set; }
    }

}
