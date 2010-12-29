/*
    Copyright © 2010 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

#include "CameraTest.h"
#include "Camera.h"

#include <QtTest/QTest>

QTEST_APPLESS_MAIN(Magnum::Test::CameraTest)

namespace Magnum { namespace Test {

void CameraTest::orthographic() {
    Camera camera;
    camera.setOrthographic(5, 1, 9);

    GLfloat a[] = {
        0.4f,   0,      0,          0,
        0,      0.4f,   0,          0,
        0,      0,      -0.25f,    0,
        0,      0,      -1.25f,     1
    };

    QVERIFY(camera.projectionMatrix() == a);
}

void CameraTest::perspective() {
    Camera camera;
    camera.setPerspective(27*PI/180, 32.0f, 100);

    GLfloat a[] = {
        4.1652994f, 0,          0,           0,
        0,          4.1652994f, 0,           0,
        0,          0,         -1.9411764f, -1,
        0,          0,         -94.1176452f, 0
    };

    QVERIFY(camera.projectionMatrix() == Matrix4(a));
}

}}
