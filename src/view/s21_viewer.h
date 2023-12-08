#ifndef CPP_S21_3DVIEWER_V2_SRC_VIEW_S21_VIEWER_H_
#define CPP_S21_3DVIEWER_V2_SRC_VIEW_S21_VIEWER_H_

#include <QMainWindow>
#include <QMessageBox>

#include "../controller/s21_controller_obj.h"
#include "./qtgifimage/gifimage/qgifimage.h"
#include "s21_strategy.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class Viewer;
}
QT_END_NAMESPACE

class Viewer : public QMainWindow {
    Q_OBJECT

public:
    Viewer(QWidget *parent = nullptr);
    ~Viewer();
    void SetControllerObj(s21::Controller *controller_obj) {
        controller_obj_ = controller_obj;
    }

    Ui::Viewer *ui; //for the strategy

private slots:

    void GifCreate();

    void SetStrategy(ViewerStrategy* strategy);

    void on_horizontalScrollBar_valueChanged(int value);

    void on_horizontalScrollBar_2_valueChanged(int value);

    void on_horizontalScrollBar_3_valueChanged(int value);

    void on_horizontalScrollBar_4_valueChanged(int value);

    void on_horizontalScrollBar_5_valueChanged(int value);

    void on_horizontalScrollBar_6_valueChanged(int value);

    void on_horizontalScrollBar_7_valueChanged(int value);

    void on_horizontalScrollBar_8_valueChanged(int value);

    void on_horizontalScrollBar_9_valueChanged(int value);

    void on_horizontalScrollBar_10_valueChanged(int value);

    void on_horizontalScrollBar_11_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_radioButton_toggled();

    void on_radioButton_2_toggled();

    void on_radioButton_3_toggled();

    void on_radioButton_4_toggled();

    void on_radioButton_5_toggled();

    void on_radioButton_6_toggled();

    void on_radioButton_7_toggled();

    void on_pushButton_21_clicked();

private:
    ViewerStrategy* strategy_;
    s21::Controller *controller_obj_;
    int dots_{}, lines_{};
    QString path_{};
    QTimer *gif_tmr_{};
    int time_{};
    double max_el_;
    QImage image_;
    QMessageBox messageBox_;
    QGifImage *gif_img_{};
    QString file_name_;
    QString fname_gif_{};

    // void gif_timer_();
    // void settings_load_();
    // void settings_save_();
    // void reset_obj_();
    // void file_proccessing_(QString file_name);
    // void error_message_(QString message);
    //or ???????????????????????????????????????
    void GifTimer();
    void SettingsLoad();
    void SettingsSave();
    void ResetObj();
    void FileProccessing(QString file_name);
    void ErrorMessage(QString message);
};
#endif  // CPP_S21_3DVIEWER_V2_SRC_VIEW_S21_VIEWER_H_
