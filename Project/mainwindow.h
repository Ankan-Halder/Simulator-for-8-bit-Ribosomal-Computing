#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTreeWidget>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    bool output_inactive_state;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addTreeRoot(QString name);
    void addTreeChild(QTreeWidgetItem *parent, QString name);
    void makeOutputInactive();
    void makeInputInactive();
    void makeOutputActive();
    void makeInputActive();
    void outputProgress();
    void inputChecker();

public slots:
    void on_actionWelcome_triggered();

    void on_actionInstruction_triggered();

    void on_actionOperation_triggered();

    void on_actionDevelopment_triggered();

    void on_actionmRNA_triggered();

    void on_actionMutation_triggered();

    void on_actionProtein_Chain_triggered();

    void on_actionInput_triggered();

    void on_actionConversion_triggered();

    void on_actionOutput_triggered();

    void on_actionBiological_Details_triggered();

    void on_actionDigital_Details_triggered();

    void on_actionPerformance_Details_triggered();

    void on_pushButton_clicked();

    void on_actionDocumentation_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_treeWidget_clicked(const QModelIndex &index);

private slots:
    void on_actionRestart_triggered();

    void on_pushButton_11_clicked();

    void on_actionWeb_triggered();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_comboBox_currentIndexChanged(int index);


    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_comboBox_3_currentIndexChanged(int index);

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
