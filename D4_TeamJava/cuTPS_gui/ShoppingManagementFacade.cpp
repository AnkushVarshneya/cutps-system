#include "ShoppingManagementFacade.h"

ShoppingManagementFacade::ShoppingManagementFacade()
{
    shopUpdateControl = new ShopUpdateControl();
//100853074
}

QList<Term*> ShoppingManagementFacade::getTermList() {
    return *shopUpdateControl->retrieveAllTerms();

}

QList<Course*> ShoppingManagementFacade::viewContent(Student *student, Term *term) throw (QString) {

    return *shopUpdateControl->retrieveContent(student, term);
}

ShoppingCart*  ShoppingManagementFacade::viewShoppingCart(Student *student) throw (QString) {
return shopUpdateControl->retrieveShoppingCart(student);
}

void ShoppingManagementFacade::addContent(Student *student, PurchasableItem *item, int quantity) throw (QString)
{
       shopUpdateControl->updateShoppingCart(student, item, quantity);
}


void ShoppingManagementFacade::emptyShoppingCart(Student *student) throw (QString)
{
    shopUpdateControl->emptyShoppingCart(student);
}

void ShoppingManagementFacade::checkOutShoppingCart(Student *student)
{
    shopUpdateControl->checkout(student);
}

PaymentInformation* ShoppingManagementFacade::getPaymentInformation(Student *student)
{
    PaymentInformation* info = shopUpdateControl->retrieveStudentPaymentInformation(student);
    if(info == NULL ) { info = new PaymentInformation();
        qDebug() << "qdebugging on billing info" ;
        qDebug() << info->getBillInfo().getStreetName();
    }
    return info;
}

bool ShoppingManagementFacade::updatePaymentInformation(Student* stu, PaymentInformation* payInfo){
    return shopUpdateControl->updatePaymentInformation(stu,payInfo);
}
