#include "s21_viewer.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <QShortcut>
#include <QTimer>
#include <QtMath>

#include "QKeyEvent"
#include "ui_s21_viewer.h"
#include "s21_strategy_r.h"

Viewer::Viewer(QWidget *parent) : QMainWindow(parent), ui(new Ui::Viewer) {
    setlocale(LC_ALL, "en_US.UTF-8");
    ui->setupUi(this);
    path_ = "/Users/";
    gif_tmr_ = new QTimer();
    auto shortcut_quit = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q), this);
    connect(shortcut_quit, &QShortcut::activated, this, &QWidget::close);
    connect(gif_tmr_, SIGNAL(timeout()), this, SLOT(GifCreate()));
    SettingsLoad();
}

Viewer::~Viewer() {
    delete gif_tmr_;
    SettingsSave();
    delete ui;
    delete strategy_;
}


void Viewer::SetStrategy(ViewerStrategy* strategy) {
    strategy_ = strategy;
}

void Viewer::GifCreate() {
    image_ = ui->widget->grabFramebuffer();
    gif_img_->addFrame(image_);
    if (time_ == 50) {
        gif_tmr_->stop();
        gif_img_->save(fname_gif_);
        time_ = 0;
        ErrorMessage("Gif saved.");
        gif_img_->~QGifImage();
        ui->pushButton_3->setText("Старт запись");
        ui->pushButton_3->setEnabled(true);
    }

    ++time_;

    if (!ui->pushButton_3->isEnabled())
        ui->pushButton_3->setText(QString::number(time_ / 10));
}

void Viewer::on_horizontalScrollBar_valueChanged(int value) {
    SetStrategy(new HorizontalScroll_fon('r', value));
    strategy_->execute(this);
}

void Viewer::on_horizontalScrollBar_2_valueChanged(int value) {
    SetStrategy(new HorizontalScroll_fon('g', value));
    strategy_->execute(this);
}

void Viewer::on_horizontalScrollBar_3_valueChanged(int value) {
    SetStrategy(new HorizontalScroll_fon('b', value));
    strategy_->execute(this);
}

void Viewer::on_horizontalScrollBar_4_valueChanged(int value) {
    SetStrategy(new HorizontalScroll_line('r', value));
    strategy_->execute(this);
}

void Viewer::on_horizontalScrollBar_5_valueChanged(int value) {
    SetStrategy(new HorizontalScroll_line('g', value));
    strategy_->execute(this);
}

void Viewer::on_horizontalScrollBar_6_valueChanged(int value) {
    SetStrategy(new HorizontalScroll_line('b', value));
    strategy_->execute(this);
}

void Viewer::on_horizontalScrollBar_7_valueChanged(int value) {
    SetStrategy(new HorizontalScroll_line('w', value));
    strategy_->execute(this);
}

void Viewer::on_horizontalScrollBar_8_valueChanged(int value) {
    SetStrategy(new HorizontalScroll_dot('r', value));
    strategy_->execute(this);
}

void Viewer::on_horizontalScrollBar_9_valueChanged(int value) {
    SetStrategy(new HorizontalScroll_dot('g', value));
    strategy_->execute(this);
}

void Viewer::on_horizontalScrollBar_10_valueChanged(int value) {
    SetStrategy(new HorizontalScroll_dot('b', value));
    strategy_->execute(this);
}

void Viewer::on_horizontalScrollBar_11_valueChanged(int value) {
    SetStrategy(new HorizontalScroll_dot('w', value));
    strategy_->execute(this);
}

void Viewer::on_pushButton_clicked() {
    file_name_ = QFileDialog::getOpenFileName(this, tr("Open Obj File"), path_, tr("OBJ Files (*.obj)"));
    if (file_name_ != "") {
        qDebug() << file_name_;
        // updates
        FileProccessing(file_name_);
    } else {
        ErrorMessage("Нет файла");
    }
}

void Viewer::on_pushButton_2_clicked() {
    QString file = QFileDialog::getSaveFileName(this, "Save as....", "name.jpeg", tr("JPEG (*.jpeg);;All Files (*)"));
    if (file != "") {
        image_ = ui->widget->grabFramebuffer();
        image_.save(file, nullptr, 100);
    } else {
        ErrorMessage("Нет папки");
    }
}

void Viewer::on_pushButton_3_clicked() {
    QString path2 = path_ + ".gif";
    fname_gif_ = QFileDialog::getSaveFileName(this, tr("Save GIF"), path2, tr("Gif Files (*.gif)"));
    if (fname_gif_ != "") {
        ui->pushButton_3->setDisabled(true);
        gif_img_ = new QGifImage;
        gif_img_->setDefaultDelay(10);
        GifTimer();
    } else {
        ErrorMessage("Нет папки");
    }
}

void Viewer::on_pushButton_4_clicked() {
    ResetObj();
    FileProccessing(file_name_);
}

void Viewer::on_pushButton_5_clicked() {
    QApplication::quit();
}

void Viewer::on_pushButton_6_clicked() {
    SetStrategy(new ScaleXYZ(controller_obj_));
    strategy_->execute(this);
}

void Viewer::on_pushButton_7_clicked() {
    SetStrategy(new ScaleX(controller_obj_));
    strategy_->execute(this);
}

void Viewer::on_pushButton_8_clicked() {
    SetStrategy(new ScaleY(controller_obj_));
    strategy_->execute(this);
}

void Viewer::on_pushButton_9_clicked() {
    SetStrategy(new ScaleZ(controller_obj_));
    strategy_->execute(this);
}

void Viewer::on_pushButton_10_clicked() {
    SetStrategy(new RotateXYZ(controller_obj_));
    strategy_->execute(this);
}

void Viewer::on_pushButton_11_clicked() {
    SetStrategy(new RotateX(controller_obj_));
    strategy_->execute(this);
}

void Viewer::on_pushButton_12_clicked() {
    SetStrategy(new RotateY(controller_obj_));
    strategy_->execute(this);
}

void Viewer::on_pushButton_13_clicked() {
    SetStrategy(new RotateZ(controller_obj_));
    strategy_->execute(this);
}

void Viewer::on_pushButton_14_clicked() {
    SetStrategy(new MoveY(controller_obj_));
    strategy_->execute(this);
}

void Viewer::on_pushButton_15_clicked() {
    SetStrategy(new MoveZmin(controller_obj_));
    strategy_->execute(this);
}

void Viewer::on_pushButton_16_clicked() {
    SetStrategy(new MoveXYZ(controller_obj_));
    strategy_->execute(this);
}

void Viewer::on_pushButton_17_clicked() {
    SetStrategy(new MoveZ(controller_obj_));
    strategy_->execute(this);
}

void Viewer::on_pushButton_18_clicked() {
    SetStrategy(new MoveYmin(controller_obj_));
    strategy_->execute(this);
}

void Viewer::on_pushButton_19_clicked() {
    SetStrategy(new MoveZmin(controller_obj_));
    strategy_->execute(this);
}

void Viewer::on_pushButton_20_clicked() {
    SetStrategy(new MoveZ(controller_obj_));
    strategy_->execute(this);
}

void Viewer::on_pushButton_21_clicked() {
    QString file = QFileDialog::getSaveFileName(this, "Save as....", "name.bmp",tr("BMP (*.bmp);;All Files (*)"));
    if (file != "") {
        image_ = ui->widget->grabFramebuffer();
        image_.save(file, "BMP");
    } else {
        ErrorMessage("Нет папки");
    }
}


void Viewer::on_radioButton_toggled() {
    SetStrategy(new PerspStrategy());
    strategy_->execute(this);
}

void Viewer::on_radioButton_2_toggled() {
    SetStrategy(new OrthoStrategy());
    strategy_->execute(this);
}

void Viewer::on_radioButton_3_toggled() {
    SetStrategy(new StippleStrategy(1));
    strategy_->execute(this);
}

void Viewer::on_radioButton_4_toggled() {
    SetStrategy(new StippleStrategy(2));
    strategy_->execute(this);
}

void Viewer::on_radioButton_5_toggled() {
    SetStrategy(new PointsStrategy(1));
    strategy_->execute(this);
}

void Viewer::on_radioButton_6_toggled() {
    SetStrategy(new PointsStrategy(3));
    strategy_->execute(this);
}

void Viewer::on_radioButton_7_toggled() {
    SetStrategy(new PointsStrategy(2));
    strategy_->execute(this);
}

void Viewer::FileProccessing(QString file_name_) {
    if (!QFile::exists(file_name_)) {
        ErrorMessage("File does not exist.");
        return;
    }
    path_ = file_name_;

    this->setWindowTitle("3D Viewer ~ " + file_name_);

    ui->label_7->setText(path_.section('/', -1, -1));
    ui->label_8->setText("Число вершин");
    ui->label_10->setText("Число линий");

    QByteArray tmp = file_name_.toLocal8Bit();
    char *file = tmp.data();

    ResetObj();
    controller_obj_->OpenObj(file);

    ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    max_el_ = 0.0;
    for (int i = 0; i < controller_obj_->GetObject().count_of_vertexes; i++) {
        if (max_el_ < controller_obj_->GetObject().vertexes[i])
            max_el_ = controller_obj_->GetObject().vertexes[i];
    }

    for (int i = 0; i < (controller_obj_->GetObject().count_of_vertexes) * 3;
         i++) {
        controller_obj_->GetObject().vertexes[i] /= max_el_;
    }

    ui->label_9->setText(
        QString::number(controller_obj_->GetObject().count_of_vertexes));
    ui->label_11->setText(
        QString::number(controller_obj_->GetObject().count_of_facets));
    ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    ui->widget->SetFacetsArr(controller_obj_->GetObject().polygons);
    ui->widget->SetLines(controller_obj_->GetObject().facet_elem);
    ui->widget->Set();
    ui->widget->update();
}

void Viewer::ErrorMessage(QString message) {
    messageBox_.setFixedSize(500, 200);
    messageBox_.information(0, "Info", message);
}

void Viewer::ResetObj() {
    qDebug() << "reset obj...";
    //what here? or delete?
}

void Viewer::GifTimer() {
    gif_tmr_->setInterval(100);
    gif_tmr_->start();
}

void Viewer::SettingsLoad() {
    //  Загружаем настройки
    qDebug() << "load settings...";
    QSettings settings("s21_3d_viewer.conf", QSettings::IniFormat);
    settings.beginGroup("Main_Settings");
    path_ = settings.value("path").toString();

    ui->radioButton->setChecked(settings.value("radioButton", true).toBool());
    ui->radioButton_2->setChecked(settings.value("radioButton_2", true).toBool());
    ui->radioButton_3->setChecked(settings.value("radioButton_3", true).toBool());
    ui->radioButton_4->setChecked(settings.value("radioButton_4", true).toBool());
    ui->radioButton_5->setChecked(settings.value("radioButton_5", true).toBool());
    ui->radioButton_6->setChecked(settings.value("radioButton_6", true).toBool());
    ui->radioButton_7->setChecked(settings.value("radioButton_7", true).toBool());

    ui->lineEdit->setText(settings.value("lineEdit").toString());
    ui->lineEdit_2->setText(settings.value("lineEdit_2").toString());
    ui->lineEdit_3->setText(settings.value("lineEdit_3").toString());
    ui->lineEdit_4->setText(settings.value("lineEdit_4").toString());
    ui->lineEdit_5->setText(settings.value("lineEdit_5").toString());
    ui->lineEdit_6->setText(settings.value("lineEdit_6").toString());
    ui->lineEdit_7->setText(settings.value("lineEdit_7").toString());
    ui->lineEdit_8->setText(settings.value("lineEdit_8").toString());
    ui->lineEdit_9->setText(settings.value("lineEdit_9").toString());
    ui->lineEdit_10->setText(settings.value("lineEdit_10").toString());
    ui->lineEdit_11->setText(settings.value("lineEdit_11").toString());
    ui->lineEdit_12->setText(settings.value("lineEdit_12").toString());

    ui->horizontalScrollBar->setValue(
        settings.value("horizontalScrollBar").toInt());
    ui->horizontalScrollBar_2->setValue(
        settings.value("horizontalScrollBar_2").toInt());
    ui->horizontalScrollBar_3->setValue(
        settings.value("horizontalScrollBar_3").toInt());
    ui->horizontalScrollBar_4->setValue(
        settings.value("horizontalScrollBar_4").toInt());
    ui->horizontalScrollBar_5->setValue(
        settings.value("horizontalScrollBar_5").toInt());
    ui->horizontalScrollBar_6->setValue(
        settings.value("horizontalScrollBar_6").toInt());
    ui->horizontalScrollBar_7->setValue(
        settings.value("horizontalScrollBar_7").toInt());
    ui->horizontalScrollBar_8->setValue(
        settings.value("horizontalScrollBar_8").toInt());
    ui->horizontalScrollBar_9->setValue(
        settings.value("horizontalScrollBar_9").toInt());
    ui->horizontalScrollBar_10->setValue(
        settings.value("horizontalScrollBar_10").toInt());
    ui->horizontalScrollBar_11->setValue(
        settings.value("horizontalScrollBar_11").toInt());
    settings.endGroup();
}

void Viewer::SettingsSave() {
    //  Сохраняем настройки
    qDebug() << "save settings...";
    QSettings settings("s21_3d_viewer.conf", QSettings::IniFormat);
    settings.beginGroup("Main_Settings");
    settings.setValue("path", path_);
    settings.setValue("radioButton", ui->radioButton->isChecked());
    settings.setValue("radioButton_2", ui->radioButton_2->isChecked());
    settings.setValue("radioButton_3", ui->radioButton_3->isChecked());
    settings.setValue("radioButton_4", ui->radioButton_4->isChecked());
    settings.setValue("radioButton_5", ui->radioButton_5->isChecked());
    settings.setValue("radioButton_6", ui->radioButton_6->isChecked());
    settings.setValue("radioButton_7", ui->radioButton_7->isChecked());

    settings.setValue("lineEdit", ui->lineEdit->text());
    settings.setValue("lineEdit_2", ui->lineEdit_2->text());
    settings.setValue("lineEdit_3", ui->lineEdit_3->text());
    settings.setValue("lineEdit_4", ui->lineEdit_4->text());
    settings.setValue("lineEdit_5", ui->lineEdit_5->text());
    settings.setValue("lineEdit_6", ui->lineEdit_6->text());
    settings.setValue("lineEdit_7", ui->lineEdit_7->text());
    settings.setValue("lineEdit_8", ui->lineEdit_8->text());
    settings.setValue("lineEdit_9", ui->lineEdit_9->text());
    settings.setValue("lineEdit_10", ui->lineEdit_10->text());
    settings.setValue("lineEdit_11", ui->lineEdit_11->text());
    settings.setValue("lineEdit_12", ui->lineEdit_12->text());

    settings.setValue("horizontalScrollBar", ui->horizontalScrollBar->value());
    settings.setValue("horizontalScrollBar_2",
                      ui->horizontalScrollBar_2->value());
    settings.setValue("horizontalScrollBar_3",
                      ui->horizontalScrollBar_3->value());
    settings.setValue("horizontalScrollBar_4",
                      ui->horizontalScrollBar_4->value());
    settings.setValue("horizontalScrollBar_5",
                      ui->horizontalScrollBar_5->value());
    settings.setValue("horizontalScrollBar_6",
                      ui->horizontalScrollBar_6->value());
    settings.setValue("horizontalScrollBar_7",
                      ui->horizontalScrollBar_7->value());
    settings.setValue("horizontalScrollBar_8",
                      ui->horizontalScrollBar_8->value());
    settings.setValue("horizontalScrollBar_9",
                      ui->horizontalScrollBar_9->value());
    settings.setValue("horizontalScrollBar_10",
                      ui->horizontalScrollBar_10->value());
    settings.setValue("horizontalScrollBar_11",
                      ui->horizontalScrollBar_11->value());
    settings.endGroup();
}
