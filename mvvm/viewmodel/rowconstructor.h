// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef ROWCONSTRUCTOR_H
#define ROWCONSTRUCTOR_H

#include "viewmodelinterfaces.h"

class QStandardItem;

namespace ModelView
{

class SessionItem;

//! Constructs row of QStandardItem's for given SessionItem.
//!
//! For example, LayerItem will generate two ViewLabelItem and ViewEmptyItem, both uneditable.
//! PropertyItem will generate ViewLabelItem and ViewDataItem.

class CORE_EXPORT DefaultRowConstructor : public RowConstructorInterface
{
public:
    QList<QStandardItem*> constructRow(SessionItem* item);
};

} // namespace ModelView

#endif // ROWCONSTRUCTOR_H
