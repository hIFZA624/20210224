using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Data_Acess_Layer
{
    class dal
    {
        public void writefile(List<string> list)
        {
            StreamWriter sw = null;
            try
            {
                //StreamWriter sw = null;
                for (int i = 0; i < list.Count; i++)
                {
                    string s = list[i];
                    string filePath = Path.Combine(Environment.CurrentDirectory, "myfile.txt");
                    sw = new StreamWriter(filePath);
                    sw.WriteLine(s);
                }
            }
            catch (Exception exception)
            {
                Console.WriteLine($"Error Type:{exception.GetType()}");
                Console.WriteLine($"Error Messege:{exception.Message}");
            }
            finally
            {
                sw.Close();
            }
        }
        public List<string> readFile()
        {
            StreamReader sr = null;
            List<string> stringlist = new List<string>();

            try
            {

                string filePath = Path.Combine(Environment.CurrentDirectory, "myfile.csv");
                sr = new StreamReader(filePath);
                string line = string.Empty;
                while ((line = sr.ReadLine()) != null)
                {
                    stringlist.Add(line);
                }
            }
            catch (Exception exception)
            {
                Console.WriteLine($"Error Type:{exception.GetType()}");
                Console.WriteLine($"Error Messege:{exception.Message}");
            }
            finally
            {
                sr.Close();
            }
            return stringlist;
        }


    }
}
