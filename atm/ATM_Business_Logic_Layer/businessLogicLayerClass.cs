using ATM_Business_Object;
using ATM_Data_Acces_Layer;
using System;
using System.Collections.Generic;
using System.Text;

namespace ATM_Business_Logic_Layer
{
    public class businessLogicLayerClass
    {
        public void getCustomerLogin(businessObject ob)
        {
            dataAcessLayerClass obj = new dataAcessLayerClass();
            obj.checkCustomerLogin(ob);
        }
    }
}
