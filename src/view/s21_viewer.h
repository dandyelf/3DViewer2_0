#ifndef CPP_S21_3DVIEWER_V2_SRC_VIEW_VIEWER_H
#define CPP_S21_3DVIEWER_V2_SRC_VIEW_VIEWER_H

#include <QMainWindow>
#include "./qtgifimage/gifimage/qgifimage.h"
#include "../model/s21_aff_transform.h"

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

  s21::Object obj;

 private slots:
 
  void OnPushButtonClicked_1();

  void OnPushButtonClicked_2();

  void OnPushButtonClicked_3();

  void OnPushButtonClicked_4();

  void OnPushButtonClicked_5();

  void OnPushButtonClicked_6();

  void OnPushButtonClicked_7();

  void OnPushButtonClicked_8();

  void OnPushButtonClicked_9();

  void OnPushButtonClicked_10();

  void OnPushButtonClicked_11();

  void OnPushButtonClicked_12();

  void OnPushButtonClicked_13();

  void OnPushButtonClicked_14();

  void OnPushButtonClicked_15();

  void OnPushButtonClicked_16();

  void OnPushButtonClicked_17();

  void OnPushButtonClicked_18();

  void OnPushButtonClicked_19();

  void OnPushButtonClicked_20();

  void OnHorizontalScrollBarValueChanged_1(int value);

  void OnHorizontalScrollBarValueChanged_2(int value);

  void OnHorizontalScrollBarValueChanged_3(int value);

  void OnHorizontalScrollBarValueChanged_4(int value);

  void OnHorizontalScrollBarValueChanged_5(int value);

  void OnHorizontalScrollBarValueChanged_6(int value);

  void OnHorizontalScrollBarValueChanged_7(int value);

  void OnHorizontalScrollBarValueChanged_8(int value);

  void OnHorizontalScrollBarValueChanged_9(int value);

  void OnHorizontalScrollBarValueChanged_10(int value);

  void OnHorizontalScrollBarValueChanged_11(int value);

  void OnRadioButtonToggled_1();

  void OnRadioButtonToggled_2();

  void OnRadioButtonToggled_3();

  void OnRadioButtonToggled_4();

  void OnRadioButtonToggled_5();

  void OnPushButtonToggled_1();

  void OnPushButtonToggled_2();

  void GifCreate();

private:
  Ui::Viewer *ui;

  int dots_{}, lines_{};
  QString path_{};
  QTimer *gif_tmr_{};
  int time_{};
  QGifImage *gif_img_{};
  QString fileName;
  QString fname_gif_{};

  void GifTimer();
  void SettingsLoad();
  void SettingsSave();
  void ResetObj();
  void FileProccessing(QString file_name);
  void ErrorMessage(QString message);
};

#endif  // CPP_S21_3DVIEWER_V2_SRC_VIEW_VIEWER_H
