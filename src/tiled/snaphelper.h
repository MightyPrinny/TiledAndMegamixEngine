/*
 * snaphelper.h
 * Copyright 2015, Thorbjørn Lindeijer <thorbjorn@lindeijer.nl>
 * Copyright 2016, Mamed Ibrahimov <ibramlab@gmail.com>
 *
 * This file is part of Tiled.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "maprenderer.h"

namespace Tiled {
namespace Internal {

class SnapHelper
{
public:
    SnapHelper(MapRenderer *renderer, Qt::KeyboardModifiers modifiers = nullptr);

    void toggleSnap();

    bool snaps() const { return mSnapToGrid || mSnapToFineGrid || mSnapToPixels; }

    QSize snapGrid() const { return QSize(mGridWidth,mGridHeigth); }

    void snap(QPointF &pixelPos) const;

private:
    MapRenderer *mRenderer;
    bool mSnapToGrid;
    bool mSnapToFineGrid;
    bool mSnapToPixels;
    int mGridWidth;
    int mGridHeigth;
};

} // namespace Internal
} // namespace Tiled
