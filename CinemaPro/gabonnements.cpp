#include "gabonnements.h"

gabonnements::gabonnements(QWidget *parent) : QWidget(parent)
{
    Ga = new QWidget(this);
    Ga->setGeometry(QRect(0,0,600,480));
    Ga->setStyleSheet("background-color: #696969");

    addbtn = new QtMaterialRaisedButton(this);
    addbtn->setText("Add Abonnement");
    addbtn->setGeometry(QRect(10,20,120,30));
    addbtn->setHaloVisible(false);

    deletebtn = new QtMaterialRaisedButton(this);
    deletebtn->setText("Remove ");
    deletebtn->setGeometry(QRect(10,70,120,30));
    deletebtn->setHaloVisible(false);

    modifybtn = new QtMaterialRaisedButton(this);
    modifybtn->setText("Modify ");
    modifybtn->setGeometry(QRect(10,120,120,30));
    modifybtn->setHaloVisible(false);

    searchbtn = new QtMaterialRaisedButton(this);
    searchbtn->setText("Search ");
    searchbtn->setGeometry(QRect(10,170,120,30));
    searchbtn->setHaloVisible(false);

    printpdf = new QtMaterialRaisedButton(this);
    printpdf->setText("Print");
    printpdf->setGeometry(QRect(10,220,120,30));
    printpdf->setHaloVisible(false);

    returnbtn = new QtMaterialRaisedButton(this);
    returnbtn->setText("Return");
    returnbtn->setGeometry(QRect(10,220,120,30));
    returnbtn->setBackgroundColor("darkred");
    returnbtn->setHaloVisible(false);
    returnbtn->setVisible(false);

    tablewidget = new QWidget(this);
    tablewidget->setGeometry(160,20,400,410);
    tablewidget->setStyleSheet("background-color: white;"
                               "border-radius: 10px");

    transparentbg = new QWidget(this);
    transparentbg->setGeometry(QRect(-500,0,500,600));
    transparentbg->setStyleSheet("background-color: rgba(0, 0, 0, 0.75);"
                                 "border-radius: 0px;");

    customdrawer = new QWidget(this);
    customdrawer->setGeometry(QRect(-300,0,300,600));
    customdrawer->setStyleSheet("background-color: white;"
                                "border-radius: 0px;");

    tempdb.abonnementtable = new QTableWidget(1,4,tablewidget);
    tempdb.abonnementtable->setColumnWidth(0,50);
    tempdb.abonnementtable->setColumnWidth(1,70);
    tempdb.abonnementtable->setColumnWidth(3,80);
    tempdb.abonnementtable->setStyleSheet("background:transparent");
    tempdb.abonnementtable->setGeometry(0,10,400,400);
    tempdb.abonnementtable->verticalHeader()->setVisible(false);
    tempdb.abonnementtable->setHorizontalHeaderLabels(QStringList() << "ID " << "Date" << "Type" << "POINTS");
    tempdb.abonnementtable->setStyleSheet("background-color: transparent");
    QHeaderView* header = tempdb.abonnementtable->horizontalHeader();
    header->setStretchLastSection(true);
    tempdb.abonnementtable->setSortingEnabled(false);
    tempdb.showabonnementtable();
    tempdb.abonnementtable->setSortingEnabled(true);

    addbtn2 = new QtMaterialRaisedButton(customdrawer);
    addbtn2->setText("Add");
    addbtn2->setHaloVisible(false);
    addbtn2->setGeometry(QRect(45,420,120,30));
    addbtn2->setVisible(false);

    searchbtn2 = new QtMaterialRaisedButton(customdrawer);
    searchbtn2->setText("Search");
    searchbtn2->setHaloVisible(false);
    searchbtn2->setGeometry(QRect(45,420,120,30));
    searchbtn2->setVisible(false);

    modifybtn2 = new QtMaterialRaisedButton(customdrawer);
    modifybtn2->setText("Modify");
    modifybtn2->setHaloVisible(false);
    modifybtn2->setGeometry(QRect(45,420,120,30));
    modifybtn2->setVisible(false);

    deletebtn2 = new QtMaterialRaisedButton(customdrawer);
    deletebtn2->setText("Delete");
    deletebtn2->setHaloVisible(false);
    deletebtn2->setGeometry(QRect(45,420,120,30));
    deletebtn2->setVisible(false);

    cancelbtn = new QtMaterialRaisedButton(customdrawer);
    cancelbtn->setText("Cancel");
    cancelbtn->setHaloVisible(false);
    cancelbtn->setGeometry(QRect(175,420,120,30));
    cancelbtn->setVisible(false);

    txtid = new QtMaterialTextField(customdrawer);
    txtid->setTextColor("black");
    txtid->setInkColor("black");
    txtid->setLabelColor("red");
    txtid->setLabel(" ID");
    txtid->setGeometry(QRect(50,0,250,60));
    txtid->setVisible(false);

    txtdate  = new QtMaterialTextField(customdrawer);
    txtdate->setTextColor("black");
    txtdate->setInkColor("black");
    txtdate->setLabel("Date");
    txtdate->setGeometry(QRect(50,70,250,60));
    txtdate->setVisible(false);

    txttype  = new QtMaterialTextField(customdrawer);
    txttype->setTextColor("black");
    txttype->setInkColor("black");
    txttype->setLabel(" Type");
    txttype->setGeometry(QRect(50,140,250,60));
    txttype->setVisible(false);

    txtpoints  = new QtMaterialTextField(customdrawer);
    txtpoints->setTextColor("black");
    txtpoints->setInkColor("black");
    txtpoints->setLabel("Points");
    txtpoints->setGeometry(QRect(50,210,250,60));
    txtpoints->setVisible(false);

    selectwarning = new QtMaterialSnackbar(tablewidget);

    connect(returnbtn,SIGNAL(clicked()),this,SLOT(show()), Qt::UniqueConnection);
    connect(searchbtn,SIGNAL(clicked()),this,SLOT(onsearchclicked()), Qt::UniqueConnection);
    connect(addbtn,SIGNAL(clicked()), this, SLOT(onaddclicked()), Qt::UniqueConnection);
    connect(cancelbtn,SIGNAL(clicked()),this,SLOT(closeadd()), Qt::UniqueConnection);
    connect(modifybtn,SIGNAL(clicked()),this,SLOT(onmodifyclicked()), Qt::UniqueConnection);
    connect(deletebtn,SIGNAL(clicked()),this,SLOT(ondeleteclicked()), Qt::UniqueConnection);
    connect(printpdf,SIGNAL(clicked()),this,SLOT(onprintclicked()), Qt::UniqueConnection);
}
void gabonnements::ondeleteclicked(){
    opendrawer();
    cancelbtn->setVisible(true);
    deletebtn2->setVisible(true);
    txtid->setVisible(true);
    txtid->setEnabled(true);
    connect(deletebtn2,SIGNAL(clicked()),this,SLOT(deleted()), Qt::UniqueConnection);
}
void gabonnements::deleted(){
    tempdb.abonnementtable->setSortingEnabled(false);
    if(!(tempdb.deleteabonnement(txtid->text().toInt()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Abonnement deleted successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    tempdb.showabonnementtable();
    tempdb.abonnementtable->setSortingEnabled(true);
    closeadd();
}
void gabonnements::show(){
    tempdb.abonnementtable->setSortingEnabled(false);
    tempdb.showabonnementtable();
    tempdb.abonnementtable->setSortingEnabled(true);
    returnbtn->setVisible(false);
}
void gabonnements::opendrawer(){
    A_customdrawer = new QPropertyAnimation(customdrawer,"geometry");
    A_customdrawer->setStartValue(customdrawer->geometry());
    A_customdrawer->setEndValue(QRect(-53,0,300,600));
    A_customdrawer->setDuration(200);
    A_customdrawer->setEasingCurve(QEasingCurve::InOutQuint);
    A_customdrawer->start(QPropertyAnimation::DeleteWhenStopped);
    A_transbg = new QPropertyAnimation(transparentbg,"geometry");
    A_transbg->setStartValue(transparentbg->geometry());
    A_transbg->setEndValue(QRect(100,0,500,600));
    A_transbg->setDuration(100);
    A_transbg->setEasingCurve(QEasingCurve::InOutQuint);
    A_transbg->start(QPropertyAnimation::DeleteWhenStopped);
}
void gabonnements::closeadd(){
    addbtn2->setVisible(false);
    modifybtn2->setVisible(false);
    deletebtn2->setVisible(false);
    searchbtn2->setVisible(false);
    cancelbtn->setVisible(false);
    txtid->setVisible(false);
    txtdate->setVisible(false);
    txtpoints->setVisible(false);
    txttype->setVisible(false);

    A_customdrawer = new QPropertyAnimation(customdrawer,"geometry");
    A_customdrawer->setStartValue(QRect(-53,0,300,600));
    A_customdrawer->setEndValue(QRect(-300,0,300,600));
    A_customdrawer->setDuration(200);
    A_customdrawer->setEasingCurve(QEasingCurve::InOutQuint);
    A_customdrawer->start(QPropertyAnimation::DeleteWhenStopped);
    A_transbg = new QPropertyAnimation(transparentbg,"geometry");
    A_transbg->setStartValue(QRect(100,0,500,600));
    A_transbg->setEndValue(QRect(-500,0,500,600));
    A_transbg->setDuration(100);
    A_transbg->setEasingCurve(QEasingCurve::InOutQuint);
    A_transbg->start(QPropertyAnimation::DeleteWhenStopped);
}
void gabonnements::onaddclicked(){
    opendrawer();
    addbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txttype->setVisible(true);
    txtpoints->setVisible(true);
    txtdate->setVisible(true);
    txtid->setVisible(true);
    txtid->setEnabled(false);
    connect(addbtn2,SIGNAL(clicked()),this,SLOT(added()), Qt::UniqueConnection);
}
void gabonnements::added(){
    tempdb.abonnementtable->setSortingEnabled(false);
    tempdb.addabonnement(txtdate->text(),txttype->text(),txtpoints->text().toInt());
    tempdb.showabonnementtable();
    tempdb.abonnementtable->setSortingEnabled(true);
    closeadd();
}
void gabonnements::onmodifyclicked(){
    opendrawer();
    modifybtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtdate->setVisible(true);
    txtpoints->setVisible(true);
    txttype->setVisible(true);
    txtid->setVisible(true);
    txtid->setEnabled(true);
    connect(modifybtn2,SIGNAL(clicked()),this,SLOT(modified()), Qt::UniqueConnection);
}
void gabonnements::modified(){
    tempdb.abonnementtable->setSortingEnabled(false);
    if(!(tempdb.modifyabonnement(txtid->text().toInt(),txtdate->text(),txttype->text(),txtpoints->text().toInt()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Abonnement modified successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    tempdb.showabonnementtable();
    tempdb.abonnementtable->setSortingEnabled(true);
    closeadd();
}
void gabonnements::onsearchclicked(){
    opendrawer();
    searchbtn2->setVisible(true);
    cancelbtn->setVisible(true);
    txtid->setVisible(true);
    txtid->setEnabled(true);
    connect(searchbtn2,SIGNAL(clicked()),this,SLOT(searched()), Qt::UniqueConnection);
}
void gabonnements::searched(){
   // tempdb.restable->clear();
    returnbtn->setVisible(true);
    if(!(tempdb.searchabonnement(txtid->text().toInt()))){
            selectwarning->addMessage("Please enter a valid ID");
            selectwarning->setTextColor("red");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();}
        else{
            selectwarning->addMessage("Abonnement found successfully");
            selectwarning->setTextColor("green");
            selectwarning->setBoxWidth(400);
            selectwarning->setGeometry(QRect(0,300,400,70));
            selectwarning->setBackgroundColor("black");
            selectwarning->show();
        }
    closeadd();
}
void gabonnements::onprintclicked(){
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Landscape);
    printer.setOutputFileName("movies.pdf");

    QTextDocument doc;

    QString text("<table><thead>");
    text.append("<tr>");
    for (int i = 0; i < tempdb.abonnementtable->columnCount(); i++) {
        text.append("<th>").append(tempdb.abonnementtable->horizontalHeaderItem(i)->data(Qt::DisplayRole).toString()).append("</th>");
    }
    text.append("</tr></thead>");
    text.append("<tbody>");
    for (int i = 0; i < tempdb.abonnementtable->rowCount(); i++) {
        text.append("<tr>");
        for (int j = 0; j < tempdb.abonnementtable->columnCount(); j++) {
            QTableWidgetItem *item = tempdb.abonnementtable->item(i, j);
            if (!item || item->text().isEmpty()) {
                tempdb.abonnementtable->setItem(i, j, new QTableWidgetItem("0"));
            }
            text.append("<td>").append(tempdb.abonnementtable->item(i, j)->text()).append("</td>");
        }
        text.append("</tr>");
    }
    text.append("</tbody></table>");
    doc.setHtml(text);
    doc.setPageSize(printer.pageRect().size());
    doc.print(&printer);
}
