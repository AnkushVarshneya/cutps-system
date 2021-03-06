#include "TextbookDetailsWindow.h"
#include "ui_TextbookDetailsWindow.h"

TextbookDetailsWindow::TextbookDetailsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextbookDetailsWindow)
{
    this->setWindowModality(Qt::WindowModal);
    ui->setupUi(this);
}

TextbookDetailsWindow*  TextbookDetailsWindow::instance = 0;

//singleton instance getter
TextbookDetailsWindow* TextbookDetailsWindow::getInstance()
{
    if (instance == 0){
    instance = new TextbookDetailsWindow();
    }
return instance;
}


TextbookDetailsWindow::TextbookDetailsWindow(Textbook &textbook, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextbookDetailsWindow)

{

    ui->setupUi(this);
    ui->textbookTitleLabel->setText(textbook.getItemTitle());

}


TextbookDetailsWindow::TextbookDetailsWindow(Textbook &textbook, QModelIndex idx, QStandardItemModel *model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextbookDetailsWindow)
{
        ui->setupUi(this);

        QList<Chapter*>::iterator it;
        for(it = textbook.getChapterList().begin(); it != textbook.getChapterList().end(); it++)
        {
            OurStandardItem *chaptersAndSectionsItem = new OurStandardItem((*it),static_cast<OurStandardItem*>(model->invisibleRootItem()) );
            model->appendRow(chaptersAndSectionsItem);
        }

       //todo: chaptersAndSectionsModel->setHorizontalHeaderLabels();
        ui->chaptersAndSectionsTreeView->setModel(model);
        ui->textbookTitleLabel->setText(textbook.getItemTitle());

}

TextbookDetailsWindow::~TextbookDetailsWindow()
{
    delete ui;
}

//set the book and model information
void TextbookDetailsWindow::setTextbookAndModel(Textbook &textbook, QModelIndex idx, QStandardItemModel *model)
{

    QList<Chapter*>::iterator it;
    for(it = textbook.getChapterList().begin(); it != textbook.getChapterList().end(); it++)
    {
        OurStandardItem *chaptersAndSectionsItem = new OurStandardItem((*it),static_cast<OurStandardItem*>(model->invisibleRootItem()) );
        model->appendRow(chaptersAndSectionsItem);
    }

   //todo: chaptersAndSectionsModel->setHorizontalHeaderLabels();
    ui->chaptersAndSectionsTreeView->setModel(model);
    ui->textbookTitleLabel->setText(textbook.getItemTitle());
    ui->textbookAuthorLabel->setText(textbook.getAuthor());
    ui->textbookEditionLabel->setText("Edition: " +textbook.getEdition());
    ui->textbookPublisherLabel->setText(textbook.getPublisher());
    ui->textbookPriceLabel->setText( QString::number(textbook.getPrice()) );
    //ui->textbookDescriptionLabel->setText(textbook.getDesc());

     ui->descriptionTextArea->clear();
     ui->descriptionTextArea->insertPlainText( textbook.getDesc() );

     ui->chaptersAndSectionsTreeView->header()->setStretchLastSection(false);
     ui->chaptersAndSectionsTreeView->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents );

}


//getters
QPushButton*     TextbookDetailsWindow::getAddSelectedItemOption()      { return ui->addSelectedItemOption ; }
QPushButton*     TextbookDetailsWindow::getCloseOption()                { return ui->closeOption ; }
QToolButton*     TextbookDetailsWindow::getAddCurrentTextbookOption()   { return ui->addCurrentTextbookOption ; }
QTreeView*       TextbookDetailsWindow::getChaptersAndSectionsView()    { return ui->chaptersAndSectionsTreeView; }
QSpinBox*        TextbookDetailsWindow::getQuantityOption()             {   return ui->quantityOption ; }
QPlainTextEdit*  TextbookDetailsWindow::getDescriptionTextArea()        {  return ui->descriptionTextArea ; }

