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

Viewer::Viewer(QWidget *parent) : QMainWindow(parent), ui(new Ui::Viewer) {
    setlocale(LC_ALL, "en_US.UTF-8");

    ui->setupUi(this);

    // controller_obj_->GetObject().count_of_vertexes = 0;
    // controller_obj_->GetObject().count_of_facets = 0;
    // controller_obj_->GetObject().facet_elem = 0;
    // controller_obj_->GetObject().vertexes = nullptr;
    // controller_obj_->GetObject().polygons = nullptr;
    path_ = "/Users/";
    gif_tmr_ = new QTimer();

    auto shortcut_quit = new QShortcut(QKeySequence(Qt::CTRL | Qt::Key_Q), this);
    connect(shortcut_quit, &QShortcut::activated, this, &QWidget::close);
    connect(gif_tmr_, SIGNAL(timeout()), this, SLOT(gif_create()));
    settings_load();
}

Viewer::~Viewer() {
    gif_tmr_->~QTimer();
    settings_save();
    delete ui;
}

void Viewer::settings_load() {
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

void Viewer::settings_save() {
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

void Viewer::on_pushButton_clicked() {
    fileName = QFileDialog::getOpenFileName(this, tr("Open Obj File"), path_,
                                            tr("OBJ Files (*.obj)"));
    if (fileName != "") {
        qDebug() << fileName;
        //updates
        file_proccessing(fileName);
    } else {
        error_message("Нет файла");
    }
}

void Viewer::on_pushButton_5_clicked() { QApplication::quit(); }

void Viewer::on_radioButton_4_toggled() {
    ui->widget->stipple = true;
    ui->widget->update();
}

void Viewer::on_radioButton_3_toggled() {
    ui->widget->stipple = false;
    ui->widget->update();
}

void Viewer::on_horizontalScrollBar_valueChanged(int value) {
    ui->widget->fon_r_ = ((double)value) / 100.0;
    ui->widget->update();
}

void Viewer::on_horizontalScrollBar_2_valueChanged(int value) {
    ui->widget->fon_g_ = ((double)value) / 100.0;
    ui->widget->update();
}

void Viewer::on_horizontalScrollBar_3_valueChanged(int value) {
    ui->widget->fon_b_ = ((double)value) / 100.0;
    ui->widget->update();
}

void Viewer::reset_obj() {
   qDebug() << "reset obj...";
   // controller_obj_->GetObject().count_of_vertexes = 0;
   // controller_obj_->GetObject().count_of_facets = 0;
   // controller_obj_->GetObject().facet_elem = 0;
   if (controller_obj_->GetObject().vertexes != NULL) free(controller_obj_->GetObject().vertexes);
   if (controller_obj_->GetObject().polygons != NULL) free(controller_obj_->GetObject().polygons);
   // controller_obj_->GetObject().vertexes = NULL;
   // controller_obj_->GetObject().polygons = NULL;
}

void Viewer::file_proccessing(QString fileName) {
    path_ = fileName;

    this->setWindowTitle("3D Viewer ~ " + fileName);

    ui->label_7->setText(path_.section('/', -1, -1));
    ui->label_8->setText("Число вершин");
    ui->label_10->setText("Число линий");

    QByteArray tmp = fileName.toLocal8Bit();
    char *file = tmp.data();

    reset_obj();
    /*int err = */controller_obj_->OpenObj(file);

ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
   // if (!err) {
       //scaling block
       double max_el = 0.0;
       for (int i = 0; i < controller_obj_->GetObject().count_of_vertexes; i++) {
           if (max_el < controller_obj_->GetObject().vertexes[i]) max_el = controller_obj_->GetObject().vertexes[i];
       }

       for (int i = 0; i < (controller_obj_->GetObject().count_of_vertexes) * 3; i++) {
           controller_obj_->GetObject().vertexes[i] /= max_el;
       }

       //end scaling block
       //set stats
       ui->label_9->setText(QString::number(controller_obj_->GetObject().count_of_vertexes));
       ui->label_11->setText(QString::number(controller_obj_->GetObject().count_of_facets));
       //end stats
       //set main data
       ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
       ui->widget->SetFacetsArr(controller_obj_->GetObject().polygons);
       ui->widget->SetLines(controller_obj_->GetObject().facet_elem);
       ui->widget->Set();
       ui->widget->update();
       //end data set
   // }
}

void Viewer::on_horizontalScrollBar_7_valueChanged(int value) {
    ui->widget->line_width = (double)value;
    ui->widget->update();
}

void Viewer::on_horizontalScrollBar_4_valueChanged(int value) {
    ui->widget->line_r_ = ((double)value) / 100.0;
    ui->widget->update();
}

void Viewer::on_horizontalScrollBar_5_valueChanged(int value) {
    ui->widget->line_g_ = ((double)value) / 100.0;
    ui->widget->update();
}

void Viewer::on_horizontalScrollBar_6_valueChanged(int value) {
    ui->widget->line_b_ = ((double)value) / 100.0;
    ui->widget->update();
}

void Viewer::on_pushButton_4_clicked() {
    reset_obj();
    file_proccessing(fileName);
}

void Viewer::on_pushButton_2_clicked() {
    QString file = QFileDialog::getSaveFileName(this, "Save as...", "name.jpg",
                                                "JPEG (*.jpeg) ;; BMP (*.bmp) ");
    if (file != "") {
        QImage image = ui->widget->grabFramebuffer();
        image.save(file, nullptr, 80);
    } else {
        error_message("Нет папки");
    }
}

void Viewer::on_pushButton_3_clicked() {
//    QString path2 = path_ + ".gif";
//    fname_gif_ = QFileDialog::getSaveFileName(this, tr("Save GIF"), path2,
//                                              tr("Gif Files (*.gif)"));
//    if (fname_gif_ != "") {
//        ui->pushButton_3->setDisabled(true);
//        gif_img_ = new QGifImage;
//        gif_img_->setDefaultDelay(10);
//        gif_timer();
//    } else {
//        error_message("Нет папки");
//    }
}

void Viewer::error_message(QString message) {
    QMessageBox messageBox;
    messageBox.setFixedSize(500, 200);
    messageBox.information(0, "Info", message);
}

void Viewer::gif_timer() {
    gif_tmr_->setInterval(100);
    gif_tmr_->start();
}

void Viewer::gif_create() {
   // QImage image = ui->widget->grabFramebuffer();
   // gif_img_->addFrame(image);
   // if (time_ == 50) {
   //     gif_tmr_->stop();
   //     gif_img_->save(fname_gif_);
   //     time_ = 0;
   //     error_message("Gif saved.");
   //     gif_img_->~QGifImage();
   //     ui->pushButton_3->setText("Старт запись");
   //     ui->pushButton_3->setEnabled(true);
   // }
   // ++time_;
   // if (!ui->pushButton_3->isEnabled())
   //     ui->pushButton_3->setText(QString::number(time_ / 10));
}

void Viewer::on_horizontalScrollBar_8_valueChanged(int value) {
    ui->widget->dot_r_ = (double)value / 100.0;
    ui->widget->update();
}

void Viewer::on_horizontalScrollBar_11_valueChanged(int value) {
    ui->widget->dot_width = value;
    ui->widget->update();
}

void Viewer::on_horizontalScrollBar_9_valueChanged(int value) {
    ui->widget->dot_g_ = (double)value / 100.0;
    ui->widget->update();
}

void Viewer::on_horizontalScrollBar_10_valueChanged(int value) {
    ui->widget->dot_b_ = (double)value / 100.0;
    ui->widget->update();
}

void Viewer::on_pushButton_16_clicked() {
    double mv_xpos = ui->lineEdit_12->text().toDouble();
    double mv_xneg = ui->lineEdit_11->text().toDouble();
    double mv_ypos = ui->lineEdit_7->text().toDouble();
    double mv_yneg = ui->lineEdit_10->text().toDouble();
    double mv_zpos = ui->lineEdit_9->text().toDouble();
    double mv_zneg = ui->lineEdit_8->text().toDouble();
    mv_xneg *= -1;
    mv_yneg *= -1;
    mv_zneg *= -1;
    controller_obj_->MoveObj('x', mv_xpos);
    controller_obj_->MoveObj('x', mv_xneg);
    controller_obj_->MoveObj('y', mv_ypos);
    controller_obj_->MoveObj('y', mv_yneg);
    controller_obj_->MoveObj('z', mv_zpos);
    controller_obj_->MoveObj('z', mv_zneg);
    ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    ui->widget->update();
}

void Viewer::on_pushButton_20_clicked() {
   double mv = ui->lineEdit_12->text().toDouble();
   controller_obj_->MoveObj('x', mv);
   ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
   ui->widget->update();
}

void Viewer::on_pushButton_19_clicked() {
   double mv = ui->lineEdit_11->text().toDouble();
   mv *= -1;
   controller_obj_->MoveObj('x', mv);
   ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
   ui->widget->update();
}

void Viewer::on_pushButton_14_clicked() {
   double mv = ui->lineEdit_7->text().toDouble();
   controller_obj_->MoveObj('y', mv);
   ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
   ui->widget->update();
}

void Viewer::on_pushButton_18_clicked() {
   double mv = ui->lineEdit_10->text().toDouble();
   mv *= -1;
   controller_obj_->MoveObj('y', mv);
   ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
   ui->widget->update();
}

void Viewer::on_pushButton_17_clicked() {
   double mv = ui->lineEdit_9->text().toDouble();
   controller_obj_->MoveObj('z', mv);
   ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
   ui->widget->update();
}

void Viewer::on_pushButton_15_clicked() {
   double mv = ui->lineEdit_8->text().toDouble();
   mv *= -1;
   controller_obj_->MoveObj('z', mv);
   ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
   ui->widget->update();
}

void Viewer::on_pushButton_6_clicked() {
    double kx = ui->lineEdit->text().toDouble();
    double ky = ui->lineEdit_2->text().toDouble();
    double kz = ui->lineEdit_3->text().toDouble();
    if (!kx || !ky || !kz) {
        ui->statusbar->showMessage("FAIL: Коэффициент масштаба равен 0!");
    } else {
        controller_obj_->ScaleObj('x', kx);
        controller_obj_->ScaleObj('y', ky);
        controller_obj_->ScaleObj('z', kz);
        ui->statusbar->clearMessage();
    }
    ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    ui->widget->update();
}

void Viewer::on_pushButton_7_clicked() {
    double koff = ui->lineEdit->text().toDouble();
   /*if (*/controller_obj_->ScaleObj('x', koff);/*) {*/
   //     ui->statusbar->showMessage("FAIL: Коэффициент масштаба равен 0!");
   // } else {
   //     ui->statusbar->clearMessage();
   // }
    ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    ui->widget->update();
}

void Viewer::on_pushButton_8_clicked() {
    double koff = ui->lineEdit_2->text().toDouble();
   /*if (*/controller_obj_->ScaleObj('y', koff);/*) {*/
   //     ui->statusbar->showMessage("FAIL: Коэффициент масштаба равен 0!");
   // } else {
   //     ui->statusbar->clearMessage();
   // }
    ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    ui->widget->update();
}

void Viewer::on_pushButton_9_clicked() {
    double koff = ui->lineEdit_3->text().toDouble();
   /*if (*/controller_obj_->ScaleObj('z', koff);/*) {*/
   //     ui->statusbar->showMessage("FAIL: Коэффициент масштаба равен 0!");
   // } else {
   //     ui->statusbar->clearMessage();
   // }
    ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    ui->widget->update();
}

void Viewer::on_pushButton_10_clicked() {
    double ax = ui->lineEdit_4->text().toDouble();
    double ay = ui->lineEdit_5->text().toDouble();
    double az = ui->lineEdit_6->text().toDouble();
    controller_obj_->RotateObj('x', ax);
    controller_obj_->RotateObj('y', ay);
    controller_obj_->RotateObj('z', az);
    ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    ui->widget->update();
}

void Viewer::on_pushButton_11_clicked() {
    double angle = ui->lineEdit_4->text().toDouble();
    controller_obj_->RotateObj('x', angle);
    ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    ui->widget->update();
}

void Viewer::on_pushButton_12_clicked() {
    double angle = ui->lineEdit_5->text().toDouble();
    controller_obj_->RotateObj('y', angle);
    ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    ui->widget->update();
}

void Viewer::on_pushButton_13_clicked() {
    double angle = ui->lineEdit_6->text().toDouble();
    controller_obj_->RotateObj('z', angle);
    ui->widget->SetVertexArr(controller_obj_->GetObject().vertexes);
    ui->widget->update();
}

void Viewer::on_radioButton_2_toggled() {
    ui->widget->SetOrtho();
    ui->widget->update();
}

void Viewer::on_radioButton_toggled() {
    ui->widget->SetPersp();
    ui->widget->update();
}

void Viewer::on_radioButton_5_toggled() {
    ui->widget->points = false;
    ui->widget->update();
}

void Viewer::on_radioButton_7_toggled() {
    ui->widget->points = true;
    ui->widget->smooth = false;
    ui->widget->update();
}

void Viewer::on_radioButton_6_toggled() {
    ui->widget->points = true;
    ui->widget->smooth = true;
    ui->widget->update();
}

// // viewer_strategy.h
// #pragma once

// class ViewerStrategy {
// public:
//     virtual void execute(Viewer* viewer) = 0;
//     virtual ~ViewerStrategy() {}
// };

// // ortho_strategy.h
// #pragma once
// #include "viewer_strategy.h"

// class OrthoStrategy : public ViewerStrategy {
// public:
//     void execute(Viewer* viewer) override {
//         viewer->ui->widget->SetOrtho();
//         viewer->ui->widget->update();
//     }
// };

// // persp_strategy.h
// #pragma once
// #include "viewer_strategy.h"

// class PerspStrategy : public ViewerStrategy {
// public:
//     void execute(Viewer* viewer) override {
//         viewer->ui->widget->SetPersp();
//         viewer->ui->widget->update();
//     }
// };

// // points_strategy.h
// #pragma once
// #include "viewer_strategy.h"

// class PointsStrategy : public ViewerStrategy {
// public:
//     void execute(Viewer* viewer) override {
//         viewer->ui->widget->points = true;
//         viewer->ui->widget->smooth = false;
//         viewer->ui->widget->update();
//     }
// };

// // viewer.h
// #include "viewer_strategy.h"

// class Viewer : public QMainWindow {
//     // ...

// private:
//     ViewerStrategy* strategy_; // Добавьте поле для стратегии

//     // ...
// };

// // viewer.cpp
// #include "ortho_strategy.h"
// #include "persp_strategy.h"
// #include "points_strategy.h"

// Viewer::Viewer(QWidget *parent) : QMainWindow(parent), ui(new Ui::Viewer) {
//     // ...
//     strategy_ = new PerspStrategy(); // Используйте конкретную стратегию по умолчанию
// }

// Viewer::~Viewer() {
//     // ...
//     delete strategy_;
// }

// // Добавьте метод для изменения стратегии
// void Viewer::setStrategy(ViewerStrategy* strategy) {
//     delete strategy_; // Освобождаем предыдущую стратегию
//     strategy_ = strategy;
// }

// // Измените соответствующие методы для использования стратегии
// void Viewer::on_radioButton_2_toggled() {
//     setStrategy(new OrthoStrategy());
//     strategy_->execute(this);
// }

// void Viewer::on_radioButton_toggled() {
//     setStrategy(new PerspStrategy());
//     strategy_->execute(this);
// }

// void Viewer::on_radioButton_5_toggled() {
//     setStrategy(new PointsStrategy());
//     strategy_->execute(this);
// }
