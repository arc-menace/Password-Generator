using System.Collections.Generic;
using System.Globalization;
using System.Text;

namespace PasswordGenerator.Services
{
    public class GeneratorService
    {
        public string Password
        { 
            get
            {
                StringBuilder stringBuilder = new();
                foreach(PasswordComponent word in PasswordComponents)
                {
                    stringBuilder.Append(word.Value);
                }

                return stringBuilder.ToString();
            }
        }
        public List<PasswordComponent>? PasswordComponents { get; set; }

        private List<string>? Words { get; set; }

        private static string Symbols = "~`!@#$%^&*()_-+={[}]|\\:;\"'<,>.?/";

        private Random Random;

        public GeneratorService(string wordFilePath)
        {
            Random = new();

            LoadWords(wordFilePath);
        }

        private void LoadWords(string wordFilePath)
        {
            if (File.Exists(wordFilePath))
            {
                Words = File.ReadAllLines(wordFilePath).ToList();
            }
            else
            {
                throw new ArgumentException("Word file could not be found.");
            }
        }

        public void GenerateNewPassword()
        {
            if(Words is not null)
            {
                PasswordComponents = new();
                TextInfo textInfo = new CultureInfo("en-US", false).TextInfo;

                //Add 3 random words
                for (int i = 0; i < 3; i++)
                {
                    string newWord = textInfo.ToTitleCase(Words[Random.Next(0, Words.Count - 1)]);

                    PasswordComponents.Add(new(newWord));
                }

                PasswordComponents.Add(new(Random.Next(1000, 9999).ToString()));

                PasswordComponents.Add(new(Symbols[Random.Next(0, Symbols.Length - 1)].ToString()));

                ShufflePassword();
            }
        }

        public void ShufflePassword()
        {
            //https://stackoverflow.com/questions/273313/randomize-a-listt

            if(PasswordComponents is not null)
            {
                int n = PasswordComponents.Count;
                while (n > 1)
                {
                    n--;
                    int k = Random.Next(n + 1);
                    PasswordComponent value = PasswordComponents[k];
                    PasswordComponents[k] = PasswordComponents[n];
                    PasswordComponents[n] = value;
                }
            }
        }
    }

    public class PasswordComponent
    {
        public string Value { get; set; }

        public PasswordComponent(string value)
        {
            Value = value;
        }   
    }
}
