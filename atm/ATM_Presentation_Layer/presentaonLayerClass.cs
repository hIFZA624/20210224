using ATM_Business_Logic_Layer;
using ATM_Business_Object;
using System;
using System.Collections.Generic;
using System.Text;

namespace ATM_Presentation_Layer
{
    class presentaonLayerClass
    {
        public void customerLogin()
        {
            Console.WriteLine("enter login");
            string login = Console.ReadLine();
            Console.WriteLine("enter passwd");
            string passwd = Console.ReadLine();
            businessObject bo = new businessObject { login = login, passwd = passwd };
            businessLogicLayerClass ob = new businessLogicLayerClass();
            ob.getCustomerLogin(bo);

        }
    }
}
