using System;
using System.Collections.Generic;
using System.Text;
using ATM_Business_Object;
using atmBusinessObject;
namespace Presentation_Layer
{
    class presentationLayer
    {
        public void customerLogin()
        {
            Console.WriteLine("enter login");
            string login = Console.ReadLine();
            Console.WriteLine("enter passwd");
            string passwd = Console.ReadLine();
            businessObject bo = new businessObject { login = login, passwd = passwd };

        }
    }
}
