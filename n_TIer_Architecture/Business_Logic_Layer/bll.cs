using System;
using System.Collections.Generic;
using System.Text;
using Data_Access_Layer;

namespace Business_Logic_Layer
{
    class bll
    {
       public  void replace()

        {
            dal result = new dal();
            List<string> list = new List<string>();
            list = result.readFile();
            for(int i=0;i<list.Count;i++)
            {
                string s = list[i];
                int lenght = s.Lenght();
                for(int i=0;i<lenght;i++)
                {
                    if(s[i]== 'P')
                    {
                        for(int i=0;s[i]!= 'T';i++)
                        {

                        }
                    }
                }
               
            }

        }
    }
}
