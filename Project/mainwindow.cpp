#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTextStream>
#include <QProcess>
#include <QDesktopServices>
#include <QUrl>
#include<QRegExpValidator>
#include<QFileDialog>
#include<QPixmap>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/image/iiest.png");
    ui->label_31->setPixmap(pix);

    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderLabel(" ");

    ui->plainTextEdit->setReadOnly(true);
    ui->textEdit->setReadOnly(true);
    ui->textEdit_2->setReadOnly(true);
    ui->textEdit_3->setReadOnly(true);
    ui->textEdit_4->setReadOnly(true);
    ui->textEdit_5->setReadOnly(true);
    ui->textEdit_6->setReadOnly(true);
    ui->textEdit_7->setReadOnly(true);
    ui->textEdit_8->setReadOnly(true);
    ui->textEdit_9->setReadOnly(true);
    ui->textEdit_10->setReadOnly(true);
    ui->textEdit_11->setReadOnly(true);
    ui->textBrowser->setReadOnly(true);
    ui->textBrowser_2->setReadOnly(true);

    ui->comboBox_2->setCurrentIndex(2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTreeRoot(QString name)
{
    QTreeWidgetItem *rootItem = new QTreeWidgetItem();
    rootItem->setText(0,name);

    ui->treeWidget->addTopLevelItem(rootItem);
    if(name == "Home")
    {
        addTreeChild(rootItem,"Welcome");
        addTreeChild(rootItem,"Instructions");
    }
    if(name == "Input")
    {
        addTreeChild(rootItem,"Operation");
        addTreeChild(rootItem,"Development");
    }
    if(name == "Output")
    {
        addTreeChild(rootItem,"Biological Data");
        addTreeChild(rootItem,"Digital Data");
        addTreeChild(rootItem,"Details Operation");
    }
    if(name == "Help")
    {
        addTreeChild(rootItem,"Documentation");
    }
}

void MainWindow::addTreeChild(QTreeWidgetItem *parent, QString name)
{
    QTreeWidgetItem *childItem = new QTreeWidgetItem();
    childItem->setText(0,name);

    parent->addChild(childItem);

    // Code to add nested children structure
    if(name=="Biological Data")
    {
        addTreeChild(childItem,"mRNA");
        addTreeChild(childItem,"Mutation");
        addTreeChild(childItem,"Protein Chain");
    }
    if(name=="Digital Data")
    {
        addTreeChild(childItem,"Input");
        addTreeChild(childItem,"Conversion");
        addTreeChild(childItem,"Output");
    }
    if(name=="Details Operation")
    {
        addTreeChild(childItem,"Biological Details");
        addTreeChild(childItem,"Digital Details");
    }
}

void MainWindow::makeOutputInactive()
{
    ui->page_4->setDisabled(true);
    ui->page_5->setDisabled(true);
    ui->page_6->setDisabled(true);
    ui->page_7->setDisabled(true);
    ui->page_8->setDisabled(true);
    ui->page_9->setDisabled(true);
    ui->page_10->setDisabled(true);
    ui->page_11->setDisabled(true);
    ui->page_13->setDisabled(true);
}

void MainWindow::makeInputInactive()
{
    ui->page_2->setDisabled(true);
}

void MainWindow::makeOutputActive()
{
    ui->page_4->setEnabled(true);
    ui->page_5->setEnabled(true);
    ui->page_6->setEnabled(true);
    ui->page_7->setEnabled(true);
    ui->page_8->setEnabled(true);
    ui->page_9->setEnabled(true);
    ui->page_10->setEnabled(true);
    ui->page_11->setEnabled(true);
    ui->page_13->setEnabled(true);
}

void MainWindow::makeInputActive()
{
    ui->page_2->setEnabled(true);
}

void delay(double sec)
{
    QTime dieTime= QTime::currentTime().addSecs(sec);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void MainWindow::outputProgress()
{
    ui->pushButton_6->setDisabled(true);
    ui->pushButton_15->setDisabled(true);

    // Set the tree widget disabled
    ui->treeWidget->setDisabled(true);

    // Set the menu bar disabled
    ui->menuHome->setDisabled(true);
    ui->menuInput->setDisabled(true);
    ui->menuOutput->setDisabled(true);
    ui->menuHelp->setDisabled(true);

    /*ui->menuDigital_Data->setDisabled(true);
    ui->menuDetails_Operation->setDisabled(true);
    ui->menuBiological_Data->setDisabled(true);*/


    ui->label_20->setText("Keep Patience!");
    ui->plainTextEdit->setPlainText("Please keep patience while your output is being generated.\nThe Menu Bar and the Hierarchy are disabled now.\nOnce the output is generated they will be enabled.\n");


    ui->textEdit_9->setText("Digital Input Recieved");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|====================|  (0 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|=>==================|  (10 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===>================|  (20 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|=====>==============|  (30 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|=======>============|  (40 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|=========>==========|  (50 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===========>========|  (60 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|=============>======|  (70 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===============>====|  (80 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|=================>==|  (90 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation.");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation..");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation...");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|====================|  (0 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|==>=================|  (10 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|====>===============|  (20 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|======>=============|  (30 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|========>===========|  (40 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|==========>=========|  (50 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|============>=======|  (60 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|==============>=====|  (70 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|================>===|  (80 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|==================>=|  (90 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)\nProtein Chain Generation Completed");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)\nProtein Chain Generation Completed\nBiological Protein Chain to Digital Output Conversion Started");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)\nProtein Chain Generation Completed\nBiological Protein Chain to Digital Output Conversion Started\n|====================|  (0 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)\nProtein Chain Generation Completed\nBiological Protein Chain to Digital Output Conversion Started\n|=>==================|  (10 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)\nProtein Chain Generation Completed\nBiological Protein Chain to Digital Output Conversion Started\n|===>================|  (20 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)\nProtein Chain Generation Completed\nBiological Protein Chain to Digital Output Conversion Started\n|=====>==============|  (30 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)\nProtein Chain Generation Completed\nBiological Protein Chain to Digital Output Conversion Started\n|=======>============|  (40 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)\nProtein Chain Generation Completed\nBiological Protein Chain to Digital Output Conversion Started\n|=========>==========|  (50 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)\nProtein Chain Generation Completed\nBiological Protein Chain to Digital Output Conversion Started\n|===========>========|  (60 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)\nProtein Chain Generation Completed\nBiological Protein Chain to Digital Output Conversion Started\n|=============>======|  (70 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)\nProtein Chain Generation Completed\nBiological Protein Chain to Digital Output Conversion Started\n|===============>====|  (80 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)\nProtein Chain Generation Completed\nBiological Protein Chain to Digital Output Conversion Started\n|=================>==|  (90 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)\nProtein Chain Generation Completed\nBiological Protein Chain to Digital Output Conversion Started\n|===================>|  (100 %)");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)\nProtein Chain Generation Completed\nBiological Protein Chain to Digital Output Conversion Started\n|===================>|  (100 %)\nBiological Protein Chain to Digital Output Conversion Completed");
    delay(1);
    ui->textEdit_9->setText("Digital Input Recieved\nDigital Input to Biological mRNA Conversion started\n|===================>|  (100 %)\nDigital Input to Biological mRNA Conversion Completed\nSearching Mutation....\nMutation Found\nProtein Chain Generation Started\n|===================>|  (100 %)\nProtein Chain Generation Completed\nBiological Protein Chain to Digital Output Conversion Started\n|===================>|  (100 %)\nBiological Protein Chain to Digital Output Conversion Completed\n\nClick on the button to see the outputs.");


    //Enable Tree Widget
    ui->treeWidget->setEnabled(true);

    // Enable the menu bar
    ui->menuHome->setEnabled(true);
    ui->menuInput->setEnabled(true);
    ui->menuOutput->setEnabled(true);
    ui->menuHelp->setEnabled(true);
    /*

    ui->menuDigital_Data->setEnabled(true);
    ui->menuDetails_Operation->setEnabled(true);
    ui->menuBiological_Data->setEnabled(true);*/

    ui->pushButton_15->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
    ui->plainTextEdit->setPlainText("Please click on the button to see the Output of the operation.");
    ui->label_20->setText("Output");
}

void MainWindow::inputChecker()
{
    ui->pushButton->setDisabled(true);
    if(ui->comboBox->currentIndex() > 0 && ui->comboBox_2->currentIndex() > 0 && ui->comboBox_3->currentIndex() > 0 ){
        QString str1 = ui->lineEdit->displayText();
        if(str1 > 0){
            if(ui->lineEdit_2->isEnabled()){
                QString str2 = ui->lineEdit_2->displayText();
                if(str2.length() > 0){
                    ui->pushButton->setEnabled(true);
                    return;
                }
                else{
                    return;
                }
            }
            ui->pushButton->setEnabled(true);
        }
    }
}




void MainWindow::on_actionWelcome_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->plainTextEdit->setPlainText("Welcome to our 8 bit mRNA Simulator.\nHere you have two modes of operation:\n1) Operation(AND, OR, XOR)\n2) Development\nPlease navigate to the operation window to give inputs.\nOur development window is still under development.");
}

void MainWindow::on_actionInstruction_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->plainTextEdit->setPlainText("Please go through the instructions carefully to avoid unwanted problems.");
}

void MainWindow::on_actionOperation_triggered()
{
    ui->stackedWidget->setCurrentIndex(2);
    if(output_inactive_state)
        ui->plainTextEdit->setPlainText("It is the Operation Input Page\n1) Please select the operation from the drop down menu (AND, OR, XOR)\n2)Give your mode of input(0 for Binary, 1 for Decimal)\n3) Provide Input 1 and Input 2.");
    else
    {
        makeInputInactive();
        ui->plainTextEdit->setPlainText("You have already given the input.\nPlease navigate through the output windows.");
    }
    inputChecker();
}

void MainWindow::on_actionDevelopment_triggered()

{
    ui->stackedWidget->setCurrentIndex(3);
    ui->plainTextEdit->setPlainText("This area is under development. Hope we can serve you soon.");
}

void MainWindow::on_actionmRNA_triggered()
{
    ui->stackedWidget->setCurrentIndex(4);
    if(output_inactive_state)
        ui->plainTextEdit->setPlainText("The output section is inactive.\nPlease provide input to make it active.\nIf you have already given the input please press the Go button.");
    else
        ui->plainTextEdit->setPlainText("Please click on the button to see the mRNA details.");
    if(output_inactive_state == false)
    {
        makeOutputActive();
    }
    else
        makeOutputInactive();
}

void MainWindow::on_actionMutation_triggered()
{
    ui->stackedWidget->setCurrentIndex(5);
    if(output_inactive_state)
        ui->plainTextEdit->setPlainText("The output section is inactive.\nPlease provide input to make it active.\nIf you have already given the input please press the Go button.");
    else
        ui->plainTextEdit->setPlainText("Please click on the button to see the Mutation details.");
    if(output_inactive_state == false)
    {
        makeOutputActive();
    }
    else
        makeOutputInactive();
}

void MainWindow::on_actionProtein_Chain_triggered()
{
    ui->stackedWidget->setCurrentIndex(6);
    if(output_inactive_state)
        ui->plainTextEdit->setPlainText("The output section is inactive.\nPlease provide input to make it active.\nIf you have already given the input please press the Go button.");
    else
        ui->plainTextEdit->setPlainText("Please click on the button to see the Protein Chain details.");
    if(output_inactive_state == false)
    {
        makeOutputActive();
    }
    else
        makeOutputInactive();
}

void MainWindow::on_actionInput_triggered()
{
    ui->stackedWidget->setCurrentIndex(7);
    if(output_inactive_state)
        ui->plainTextEdit->setPlainText("The output section is inactive.\nPlease provide input to make it active.\nIf you have already given the input please press the Go button.");
    else
        ui->plainTextEdit->setPlainText("This shows the Inputs provided in this current session.");
    if(output_inactive_state == false)
    {
        makeOutputActive();
    }
    else
        makeOutputInactive();
}

void MainWindow::on_actionConversion_triggered()
{
    ui->stackedWidget->setCurrentIndex(8);
    if(output_inactive_state)
        ui->plainTextEdit->setPlainText("The output section is inactive.\nPlease provide input to make it active.\nIf you have already given the input please press the Go button.");
    else
        ui->plainTextEdit->setPlainText("Please click on the button to see the mRNA Conversion details.");
    if(output_inactive_state == false)
    {
        makeOutputActive();
    }
    else
        makeOutputInactive();
}

void MainWindow::on_actionOutput_triggered()
{
    ui->stackedWidget->setCurrentIndex(9);
    if(output_inactive_state)
        ui->plainTextEdit->setPlainText("The output section is inactive.\nPlease provide input to make it active.\nIf you have already given the input please press the Go button.");
    else
        ui->plainTextEdit->setPlainText("Please click on the button to see the Output of the operation.");
    if(output_inactive_state == false)
    {
        makeOutputActive();
    }
    else
        makeOutputInactive();
}

void MainWindow::on_actionBiological_Details_triggered()
{
    ui->stackedWidget->setCurrentIndex(10);
    if(output_inactive_state)
        ui->plainTextEdit->setPlainText("The output section is inactive.\nPlease provide input to make it active.\nIf you have already given the input please press the Go button.");
    else
        ui->plainTextEdit->setPlainText("Please click on the button to see the Biological Details.");
    if(output_inactive_state == false)
    {
        makeOutputActive();
    }
    else
        makeOutputInactive();
}

void MainWindow::on_actionDigital_Details_triggered()
{
    ui->stackedWidget->setCurrentIndex(11);
    if(output_inactive_state)
        ui->plainTextEdit->setPlainText("The output section is inactive.\nPlease provide input to make it active.\nIf you have already given the input please press the Go button.");
    else
        ui->plainTextEdit->setPlainText("Please click on the button to see the Digital details.");
    if(output_inactive_state == false)
    {
        makeOutputActive();
    }
    else
        makeOutputInactive();
}

void MainWindow::on_actionPerformance_Details_triggered()
{
    ui->stackedWidget->setCurrentIndex(12);
    if(output_inactive_state)
        ui->plainTextEdit->setPlainText("The section is inactive.\nPlease provide input to make it active.\nIf you have already given the input please press the Go button.");
    else
        ui->plainTextEdit->setPlainText("Please click on the button to see the Performance details.");
    if(output_inactive_state == false)
    {
        makeOutputActive();
    }
    else
        makeOutputInactive();

}

void MainWindow::on_pushButton_clicked()
{
    // Make a Folder in home path
    QDir dir(QDir::homePath());
    dir.mkdir("Ribosomal_Simulator");

    //Project path
    QString proPath = QDir::homePath() + "/Ribosomal_Simulator";
    QDir dir2(proPath);
    dir2.mkdir("Input"); // Create Input Folder
    dir2.mkdir("Output"); //Create Output Folder

    //Input Folder path
    QString inPath = proPath + "/Input";

    // To write type of operation in file
    QFile file1(inPath+"/operation.txt");
    file1.open(QIODevice::WriteOnly);
    QTextStream stream1(&file1);
    if(ui->comboBox->currentIndex() != 0 && ui->comboBox_3->currentIndex() != 0)
    {
        stream1<<ui->comboBox_3->currentText().toLower();
    }
    file1.close();

    // To write the input mode in file
    QFile file2(inPath+"/mode.txt");
    file2.open(QIODevice::WriteOnly);
    QTextStream stream2(&file2);
    stream2<<ui->comboBox_2->currentIndex()-1;
    file2.close();

    // To write Input 1
    QFile file3(inPath+"/number1.txt");
    file3.open(QIODevice::WriteOnly);
    QTextStream stream3(&file3);
    stream3<<ui->lineEdit->displayText();
    file3.close();

    // To write Input 2
    QFile file4(inPath+"/number2.txt");
    file4.open(QIODevice::WriteOnly);
    QTextStream stream4(&file4);
    stream4<<ui->lineEdit_2->displayText();
    file4.close();


    output_inactive_state = false;

}


void MainWindow::on_actionDocumentation_triggered()
{
    ui->stackedWidget->setCurrentIndex(13);
    ui->plainTextEdit->setPlainText("It is the Documentation Page.");
}

void MainWindow::on_pushButton_2_clicked()
{
    QString outPath = QDir::homePath()+"/Ribosomal_Simulator/Output";
    QFile file1(outPath + "/mrna.txt");
    file1.open(QIODevice::ReadOnly);
    QTextStream in1(&file1);
    QString text1 = in1.readAll();
    ui->textEdit->setText(text1);
    file1.close();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString outPath = QDir::homePath()+"/Ribosomal_Simulator/Output";
    QFile file1(outPath+"/mutation.txt");
    file1.open(QIODevice::ReadOnly);
    QTextStream in1(&file1);
    QString text1 = in1.readAll();
    ui->textEdit_2->setText(text1);
    file1.close();
}

void MainWindow::on_pushButton_4_clicked()
{
    QString outPath = QDir::homePath()+"/Ribosomal_Simulator/Output";
        QFile file1(outPath+"/protein.txt");
        file1.open(QIODevice::ReadOnly);
        QTextStream in1(&file1);
        QString text1 = in1.readAll();
        ui->textEdit_3->setText(text1);
        file1.close();
}

void MainWindow::on_pushButton_5_clicked()
{
    QString outPath = QDir::homePath()+"/Ribosomal_Simulator/Output";
        QFile file1(outPath+"/digitalIP.txt");
        file1.open(QIODevice::ReadOnly);
        QTextStream in1(&file1);
        QString text1 = in1.readAll();
        ui->textEdit_8->setText(text1);
        file1.close();
}

void MainWindow::on_pushButton_6_clicked()
{
    QString outPath = QDir::homePath()+"/Ribosomal_Simulator/Output";

    QFile file1(outPath+"/digitalOP.txt");
    file1.open(QIODevice::ReadOnly);
    QTextStream in1(&file1);
    QString text1 = in1.readAll();
    ui->textEdit_9->setText(text1);
    file1.close();
}

void MainWindow::on_pushButton_7_clicked()
{
    QString outPath = QDir::homePath()+"/Ribosomal_Simulator/Output";

    QFile file1(outPath+"/biodetails.txt");
    file1.open(QIODevice::ReadOnly);
    QTextStream in1(&file1);
    QString text1 = in1.readAll();
    ui->textEdit_11->setText(text1);
    file1.close();
}

void MainWindow::on_pushButton_8_clicked()
{
    QString outPath = QDir::homePath()+"/Ribosomal_Simulator/Output";

    QFile file1(outPath+"/digdetails.txt");
    file1.open(QIODevice::ReadOnly);
    QTextStream in1(&file1);
    QString text1 = in1.readAll();
    ui->textEdit_10->setText(text1);
    file1.close();
}



void MainWindow::on_pushButton_9_clicked()
{
    QString inPath = QDir::homePath()+"/Ribosomal_Simulator/Input";

    // To write type of operation in file
    QFile file1(inPath+"/operation.txt");
    file1.open(QIODevice::ReadOnly);
    QTextStream stream1(&file1);
    QString text1 = stream1.readAll();
    ui->textEdit_4->setText(text1.toUpper());
    file1.close();

    QFile file2(inPath+"/mode.txt");
    file2.open(QIODevice::ReadOnly);
    QTextStream stream2(&file2);
    QString text2 = stream2.readAll();
    if(text2 == "0")
        ui->textEdit_5->setText("Binary");
    if(text2 == "1")
        ui->textEdit_5->setText("Decimal");
    file2.close();

    // To write Input 1
    QFile file3(inPath+"/number1.txt");
    file3.open(QIODevice::ReadOnly);
    QTextStream stream3(&file3);
    QString text3 = stream3.readAll();
    ui->textEdit_6->setText(text3);
    file3.close();

    // To write Input 2
    QFile file4(inPath+"/number2.txt");
    file4.open(QIODevice::ReadOnly);
    QTextStream stream4(&file4);
    QString text4 = stream4.readAll();
    ui->textEdit_7->setText(text4);
    file4.close();

}

void MainWindow::on_treeWidget_clicked(const QModelIndex &index)
{
    int row = index.row();
    int parent = index.parent().row();
    int grandparent = index.parent().parent().row();
    if(parent == 0 && row== 0)
        on_actionWelcome_triggered();
    if(parent == 0 && row== 1)
        on_actionInstruction_triggered();
    if(parent == 1 && row== 0)
        on_actionOperation_triggered();
    if(parent == 1 && row== 1)
        on_actionDevelopment_triggered();
    if(grandparent == 2)
    {
        if(parent==0)
        {
            if(row==0)
                on_actionmRNA_triggered();
            if(row==1)
                on_actionMutation_triggered();
            if(row==2)
                on_actionProtein_Chain_triggered();
        }
        if(parent==1)
        {
            if(row==0)
                on_actionInput_triggered();
            if(row==1)
                on_actionConversion_triggered();
            if(row==2)
                on_actionOutput_triggered();
        }
        if(parent==2)
        {
            if(row ==0)
                on_actionBiological_Details_triggered();
            if(row ==1)
                on_actionDigital_Details_triggered();
            if(row ==2)
                on_actionPerformance_Details_triggered();
        }
    }
    if(parent == 3 && row== 0)
        on_actionDocumentation_triggered();

}

void MainWindow::on_actionRestart_triggered()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void MainWindow::on_pushButton_11_clicked()
{
    QString link="https://www.google.com";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_actionWeb_triggered()
{
    QString link="https://www.google.com";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    if(ui->comboBox_2->currentIndex() == 2) // if decimal is selected
    {
        QRegExpValidator *input = new QRegExpValidator(QRegExp("[0-1]{1}[0-9]{2}|[0-9]{1}|[0-9]{2}|2[0-4]{1}[0-9]{1}|25[0-5]{1}"));
        ui->lineEdit->setValidator(input);
        ui->lineEdit_2->setValidator(input);
        ui->lineEdit->setToolTip("You have selected DECIMAL. You can input any number from 0 to 256 inclusive.");
        ui->lineEdit->setPlaceholderText("Any Decimal Number from 0 to 256 inclusive");
        ui->lineEdit_2->setPlaceholderText("Any Decimal Number from 0 to 256 inclusive");
        ui->lineEdit_2->setToolTip("You have selected DECIMAL. You can input any number from 0 to 256 inclusive.");

    }

    if(ui->comboBox_2->currentIndex() == 1) // if binary is selected
    {

        QRegExpValidator *input = new QRegExpValidator(QRegExp("[0-1]{8}"));
        ui->lineEdit->setValidator(input);
        ui->lineEdit_2->setValidator(input);
        ui->lineEdit->setToolTip("You have selected BINARY. You can input any 8 bit binary number.");
        ui->lineEdit_2->setToolTip("You have selected BINARY. You can input any 8 bit binary number.");
        ui->lineEdit->setPlaceholderText("Any 8 Bit Binary Number");
        ui->lineEdit_2->setPlaceholderText("Any 8 Bit Binary Number");
    }
    on_pushButton_10_clicked();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index == 0)
    {
        ui->comboBox_3->clear();
        ui->comboBox_3->setEditable(false);
    }
    else if(index == 1)
    {
        ui->comboBox_3->clear();
        ui->comboBox_3->addItem("Select");
        ui->comboBox_3->addItem("XOR");
        ui->comboBox_3->addItem("OR");
        ui->comboBox_3->addItem("AND");
        ui->comboBox_3->addItem("NOT");
        ui->comboBox_3->addItem("XNOR");
        ui->comboBox_3->addItem("NOR");
        ui->comboBox_3->addItem("NAND");
    }
    else if(index == 2)
    {
        ui->comboBox_3->clear();
        ui->comboBox_3->addItem("Select");
        ui->comboBox_3->addItem("TWOSCOMPLEMENT");
        ui->comboBox_3->addItem("ADDITION");
        ui->comboBox_3->addItem("SUBTRACTION");
        ui->comboBox_3->addItem("MULTIPLICATION");
        ui->comboBox_3->addItem("DIVISION");
    }
    else if(index == 3)
    {
        ui->comboBox_3->clear();
        ui->comboBox_3->addItem("Select");
        ui->comboBox_3->addItem("COMPARATOR");
        ui->comboBox_3->addItem("LOGICALLEFTSHIFT");
        ui->comboBox_3->addItem("LOGICALRIGHTSHIFT");
        ui->comboBox_3->addItem("ARITHMETICSHIFT");
        ui->comboBox_3->addItem("CIRCULARLEFTSHIFT");
        ui->comboBox_3->addItem("CIRCULARRIGHTSHIFT");
    }
    inputChecker();
}

void MainWindow::on_pushButton_12_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"Save File");
    QFile file10(path);
    file10.open(QIODevice::WriteOnly|QIODevice::Append);
    QTextStream stream10(&file10);
    stream10<<ui->textEdit->toPlainText();
    file10.close();
}

void MainWindow::on_pushButton_13_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"Save File");
    QFile file11(path);
    file11.open(QIODevice::WriteOnly|QIODevice::Append);
    QTextStream stream11(&file11);
    stream11<<ui->textEdit_11->toPlainText();
    file11.close();
}



void MainWindow::on_pushButton_14_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"Save File");
    QFile file12(path);
    file12.open(QIODevice::WriteOnly|QIODevice::Append);
    QTextStream stream12(&file12);
    stream12<<ui->textEdit_10->toPlainText();
    file12.close();
}

void MainWindow::on_pushButton_15_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"Save File");
    QFile file15(path);
    file15.open(QIODevice::WriteOnly|QIODevice::Append);
    QTextStream stream15(&file15);
    stream15<<ui->textEdit_9->toPlainText();
    file15.close();
}

void MainWindow::on_pushButton_16_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"Save File");
    QFile file16(path);
    file16.open(QIODevice::WriteOnly|QIODevice::Append);
    QTextStream stream16(&file16);
    stream16<<ui->textEdit_8->toPlainText();
    file16.close();
}




void MainWindow::on_pushButton_17_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"Save File");
    QFile file17(path);
    file17.open(QIODevice::WriteOnly|QIODevice::Append);
    QTextStream stream17(&file17);
    stream17<<ui->textEdit_3->toPlainText();
    file17.close();
}



void MainWindow::on_pushButton_18_clicked()
{
    QString path = QFileDialog::getSaveFileName(this,"Save File");
    QFile file18(path);
    file18.open(QIODevice::WriteOnly|QIODevice::Append);
    QTextStream stream18(&file18);
    stream18<<ui->textEdit_2->toPlainText();
    file18.close();
}

void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_2->setEnabled("True");
    if(arg1 == "LOGICALLEFTSHIFT" || arg1 == "LOGICALRIGHTSHIFT" || arg1 == "ARITHMETICSHIFT" || arg1 == "CIRCULARLEFTSHIFT" || arg1 == "CIRCULARRIGHTSHIFT" || arg1 == "TWOSCOMPLEMENT" || arg1 == "NOT")
    {
        ui->lineEdit_2->setDisabled("True");
        ui->label_7->setText("Input 2");
        ui->label_7->setDisabled(true);
    }
    else{
        ui->lineEdit_2->setEnabled("True");
        ui->label_7->setText("Input 2*");
        ui->label_7->setEnabled(true);
    }
    inputChecker();
}

void MainWindow::on_pushButton_19_clicked()
{
    QString outPath = QDir::homePath()+"/Ribosomal_Simulator/Output";

    QFile file1(outPath+"/energy.txt");
    file1.open(QIODevice::ReadOnly);
    QTextStream in1(&file1);
    QString text1 = in1.readAll();
    ui->textBrowser->setText(text1);
    file1.close();
}

void MainWindow::on_pushButton_20_clicked()
{
    QString outPath = QDir::homePath()+"/Ribosomal_Simulator/Output";

    QFile file1(outPath+"/time.txt");
    file1.open(QIODevice::ReadOnly);
    QTextStream in1(&file1);
    QString text1 = in1.readAll();
    ui->textBrowser_2->setText(text1);
    file1.close();
}

void MainWindow::on_pushButton_21_clicked()
{

    QString link="https://pdfhost.io/v/G05xFtClL_DocumentationRibosomeSimulatorpdf.pdf";
    QDesktopServices::openUrl(QUrl(link));

}

void MainWindow::on_pushButton_22_clicked()
{
    QString link="https://pdfhost.io/v/r9t30DjvO_User_Guidepdf.pdf";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
   inputChecker();
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    inputChecker();
}

void MainWindow::on_comboBox_3_currentIndexChanged(int index)
{
    inputChecker();
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    inputChecker();
}



