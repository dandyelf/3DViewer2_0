#ifndef VIEW_S21_STRA_H_
#define VIEW_S21_STRA_H_

#include "s21_viewer.h"
#include "ui_s21_viewer.h"
#include "../controller/s21_controller_obj.h"

class Viewer;

class ViewerStrategy {
public:
    virtual void execute(Viewer* viewer) = 0;
    virtual ~ViewerStrategy() {}
};

#endif // VIEW_S21_STRA_H_
