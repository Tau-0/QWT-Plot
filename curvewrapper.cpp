#include "curvewrapper.h"

CurveWrapper::CurveWrapper() {
    checkbox = make_unique<ModifiedCheckBox>();
    curve = make_unique<QwtPlotCurve>();
    function = nullptr;
}
