#pragma once

#include "nova/types.h"
#include "nova/math.h"
#include "nova/vec3.h"

namespace nova
{
    inline static bool
    operator==(const Mat4 &A, const Mat4 &B)
    {
        return
            A[0][0] == B[0][0] && A[0][1] == B[0][1] && A[0][2] == B[0][2] && A[0][3] == B[0][3] &&
            A[1][0] == B[1][0] && A[1][1] == B[1][1] && A[1][2] == B[1][2] && A[1][3] == B[1][3] &&
            A[2][0] == B[2][0] && A[2][1] == B[2][1] && A[2][2] == B[2][2] && A[2][3] == B[2][3] &&
            A[3][0] == B[3][0] && A[3][1] == B[3][1] && A[3][2] == B[3][2] && A[3][3] == B[3][3];
    }

    inline static bool
    operator!=(const Mat4 &A, const Mat4 &B)
    {
        return !(A == B);
    }

    inline static Mat4
    operator+(const Mat4 &A, const Mat4 &B)
    {
        return Mat4{
            A[0][0] + B[0][0], A[0][1] + B[0][1], A[0][2] + B[0][2], A[0][3] + B[0][3],
            A[1][0] + B[1][0], A[1][1] + B[1][1], A[1][2] + B[1][2], A[1][3] + B[1][3],
            A[2][0] + B[2][0], A[2][1] + B[2][1], A[2][2] + B[2][2], A[2][3] + B[2][3],
            A[3][0] + B[3][0], A[3][1] + B[3][1], A[3][2] + B[3][2], A[3][3] + B[3][3]
        };
    }

    inline static Mat4 &
    operator+=(Mat4 &A, const Mat4 &B)
    {
        A = A + B;
        return A;
    }

    inline static Mat4
    operator-(const Mat4 &M)
    {
        return Mat4{
            -M[0][0], -M[0][1], -M[0][2], -M[0][3],
            -M[1][0], -M[1][1], -M[1][2], -M[1][3],
            -M[2][0], -M[2][1], -M[2][2], -M[2][3],
            -M[3][0], -M[3][1], -M[3][2], -M[3][3]
        };
    }

    inline static Mat4
    operator-(const Mat4 &A, const Mat4 &B)
    {
        return Mat4{
            A[0][0] - B[0][0], A[0][1] - B[0][1], A[0][2] - B[0][2], A[0][3] - B[0][3],
            A[1][0] - B[1][0], A[1][1] - B[1][1], A[1][2] - B[1][2], A[1][3] - B[1][3],
            A[2][0] - B[2][0], A[2][1] - B[2][1], A[2][2] - B[2][2], A[2][3] - B[2][3],
            A[3][0] - B[3][0], A[3][1] - B[3][1], A[3][2] - B[3][2], A[3][3] - B[3][3]
        };
    }

    inline static Mat4 &
    operator-=(Mat4 &A, const Mat4 &B)
    {
        A = A - B;
        return A;
    }

    inline static Mat4
    operator*(const Mat4 &M, float f)
    {
        return Mat4{
            M[0][0] * f, M[0][1] * f, M[0][2] * f, M[0][3] * f,
            M[1][0] * f, M[1][1] * f, M[1][2] * f, M[1][3] * f,
            M[2][0] * f, M[2][1] * f, M[2][2] * f, M[2][3] * f,
            M[3][0] * f, M[3][1] * f, M[3][2] * f, M[3][3] * f
        };
    }

    inline static Mat4
    operator*(float f, const Mat4 &M)
    {
        return M * f;
    }

    inline static Mat4 &
    operator*=(Mat4 &M, float f)
    {
        M = M * f;
        return M;
    }

    inline static Vec4
    operator*(const Vec4 &v, const Mat4 &M)
    {
        return Vec4{
            v.x * M[0][0] + v.y * M[1][0] + v.z * M[2][0] + v.w * M[3][0],
            v.x * M[0][1] + v.y * M[1][1] + v.z * M[2][1] + v.w * M[3][1],
            v.x * M[0][2] + v.y * M[1][2] + v.z * M[2][2] + v.w * M[3][2],
            v.x * M[0][3] + v.y * M[1][3] + v.z * M[2][3] + v.w * M[3][3]
        };
    }

    inline static Mat4
    operator*(const Mat4 &A, const Mat4 &B)
    {
        Mat4 C;

        C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0] + A[0][2] * B[2][0] + A[0][3] * B[3][0];
        C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1] + A[0][2] * B[2][1] + A[0][3] * B[3][1];
        C[0][2] = A[0][0] * B[0][2] + A[0][1] * B[1][2] + A[0][2] * B[2][2] + A[0][3] * B[3][2];
        C[0][3] = A[0][0] * B[0][3] + A[0][1] * B[1][3] + A[0][2] * B[2][3] + A[0][3] * B[3][3];

        C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0] + A[1][2] * B[2][0] + A[1][3] * B[3][0];
        C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1] + A[1][2] * B[2][1] + A[1][3] * B[3][1];
        C[1][2] = A[1][0] * B[0][2] + A[1][1] * B[1][2] + A[1][2] * B[2][2] + A[1][3] * B[3][2];
        C[1][3] = A[1][0] * B[0][3] + A[1][1] * B[1][3] + A[1][2] * B[2][3] + A[1][3] * B[3][3];

        C[2][0] = A[2][0] * B[0][0] + A[2][1] * B[1][0] + A[2][2] * B[2][0] + A[2][3] * B[3][0];
        C[2][1] = A[2][0] * B[0][1] + A[2][1] * B[1][1] + A[2][2] * B[2][1] + A[2][3] * B[3][1];
        C[2][2] = A[2][0] * B[0][2] + A[2][1] * B[1][2] + A[2][2] * B[2][2] + A[2][3] * B[3][2];
        C[2][3] = A[2][0] * B[0][3] + A[2][1] * B[1][3] + A[2][2] * B[2][3] + A[2][3] * B[3][3];

        C[3][0] = A[3][0] * B[0][0] + A[3][1] * B[1][0] + A[3][2] * B[2][0] + A[3][3] * B[3][0];
        C[3][1] = A[3][0] * B[0][1] + A[3][1] * B[1][1] + A[3][2] * B[2][1] + A[3][3] * B[3][1];
        C[3][2] = A[3][0] * B[0][2] + A[3][1] * B[1][2] + A[3][2] * B[2][2] + A[3][3] * B[3][2];
        C[3][3] = A[3][0] * B[0][3] + A[3][1] * B[1][3] + A[3][2] * B[2][3] + A[3][3] * B[3][3];

        return C;
    }

    inline static Mat4
    operator/(const Mat4 &M, float f)
    {
        return Mat4{
            M[0][0] / f, M[0][1] / f, M[0][2] / f, M[0][3] / f,
            M[1][0] / f, M[1][1] / f, M[1][2] / f, M[1][3] / f,
            M[2][0] / f, M[2][1] / f, M[2][2] / f, M[2][3] / f,
            M[3][0] / f, M[3][1] / f, M[3][2] / f, M[3][3] / f
        };
    }

    inline static Mat4
    operator/(float f, const Mat4 &M)
    {
        return M / f;
    }

    inline static Mat4 &
    operator/=(Mat4 &M, float f)
    {
        M = M / f;
        return M;
    }

    inline static Mat4
    mat4_identity()
    {
        return Mat4{
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
    }

    inline static Mat4
    mat4_translation(float tx, float ty, float tz)
    {
        return Mat4{
            1,  0,  0, 0,
            0,  1,  0, 0,
            0,  0,  1, 0,
            tx, ty, tz, 1
        };
    }

    inline static Mat4
    mat4_translation(const Vec3 &translation)
    {
        return mat4_translation(translation.x, translation.y, translation.z);
    }

    inline static Mat4
    mat4_rotation_x(float pitch)
    {
        float c = cos(pitch);
        float s = sin(pitch);

        return Mat4{
            1,  0, 0, 0,
            0,  c, s, 0,
            0, -s, c, 0,
            0,  0, 0, 1
        };
    }

    inline static Mat4
    mat4_rotation_y(float head)
    {
        float c = cos(head);
        float s = sin(head);

        return Mat4{
            c, 0, -s, 0,
            0, 1,  0, 0,
            s, 0,  c, 0,
            0, 0,  0, 1
        };
    }

    inline static Mat4
    mat4_rotation_z(float roll)
    {
        float c = cos(roll);
        float s = sin(roll);

        return Mat4{
             c, s, 0, 0,
            -s, c, 0, 0,
             0, 0, 1, 0,
             0, 0, 0, 1
        };
    }

    inline static Mat4
    mat4_rotation_axis(const Vec3 &axis, float angle)
    {
        float c = cos(angle);
        float s = sin(angle);

        float x = axis.x;
        float y = axis.y;
        float z = axis.z;

        return Mat4{
            c + (1-c)*x*x  , (1-c)*x*y + s*z, (1-c)*x*z - s*y, 0.0f,
            (1-c)*x*y - s*z, c + (1-c)*y*y  , (1-c)*y*z + s*x, 0.0f,
            (1-c)*x*z + s*y, (1-c)*y*z - s*x, c + (1-c)*z*z  , 0.0f,
            0.0f           ,            0.0f,            0.0f, 1.0f
        };
    }

    inline static Mat4
    mat4_euler(float pitch, float head, float roll)
    {
        float sh = sin(head);
        float ch = cos(head);
        float sp = sin(pitch);
        float cp = cos(pitch);
        float sr = sin(roll);
        float cr = cos(roll);

        // order yxz
        return Mat4{
             cr*ch - sr*sp*sh, sr*ch + cr*sp*sh, -cp*sh, 0.0f,
            -sr*cp           , cr*cp           ,  sp   , 0.0f,
             cr*sh + sr*sp*ch, sr*sh - cr*sp*ch,  cp*ch, 0.0f,
             0.0f            , 0.0f            ,  0.0f  ,1.0f
        };
    }

    inline static Mat4
    mat4_euler(const Vec3 &rotation)
    {
        return mat4_euler(rotation.x, rotation.y, rotation.z);
    }

    inline static Vec3
    mat4_euler_angles(const Mat4 &E)
    {
        return Vec3{
            asin(E[1][2]),
            atan2(-E[0][2], E[2][2]),
            atan2(-E[1][0], E[1][1])
        };
    }

    inline static Mat4
    mat4_scaling(float sx, float sy, float sz)
    {
        return Mat4{
            sx,  0,  0, 0,
             0, sy,  0, 0,
             0,  0, sz, 0,
             0,  0,  0, 1
        };
    }

    inline static Mat4
    mat4_scaling(const Vec3 &scaling)
    {
        return mat4_scaling(scaling.x, scaling.y, scaling.z);
    }

    inline static Mat4
    mat4_shearing_xy(float s)
    {
        return Mat4{
            1, 0, 0, 0,
            s, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
    }

    inline static Mat4
    mat4_shearing_xz(float s)
    {
        return Mat4{
            1, 0, 0, 0,
            0, 1, 0, 0,
            s, 0, 1, 0,
            0, 0, 0, 1
        };
    }

    inline static Mat4
    mat4_shearing_yx(float s)
    {
        return Mat4{
            1, s, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
    }

    inline static Mat4
    mat4_shearing_yz(float s)
    {
        return Mat4{
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, s, 1, 0,
            0, 0, 0, 1
        };
    }

    inline static Mat4
    mat4_shearing_zx(float s)
    {
        return Mat4{
            1, 0, s, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
    }

    inline static Mat4
    mat4_shearing_zy(float s)
    {
        return Mat4{
            1, 0, 0, 0,
            0, 1, s, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
    }

    inline static Mat4
    mat4_look_at(const Vec3 &eye, const Vec3 &target, const Vec3 &up)
    {
        Vec3 axis_z = normalize(eye - target);
        Vec3 axis_x = normalize(cross(up, axis_z));
        Vec3 axis_y = cross(axis_z, axis_x);

        Vec3 t = {
            -dot(eye, axis_x),
            -dot(eye, axis_y),
            -dot(eye, axis_z)
        };

        return Mat4{
            axis_x.x, axis_y.x, axis_z.x, 0.0f,
            axis_x.y, axis_y.y, axis_z.y, 0.0f,
            axis_x.z, axis_y.z, axis_z.z, 0.0f,
                 t.x,      t.y,      t.z, 1.0f
        };
    }

    // TODO[Waleed]: add unittests
    inline static Mat4
    mat4_ortho(float left, float right, float bottom, float top, float znear, float zfar)
    {
        Mat4 M{};

        M[0][0] = 2.0f / (right - left);
        M[3][0] = -(right + left) / (right - left);

        M[1][1] = 2.0f / (top - bottom);
        M[3][1] = -(top + bottom) / (top - bottom);

        // to map z to [-1, 1] use
        // M[2][2] = -2.0f / (zfar - znear)
        // M[3][2] = -(zfar + znear) / (zfar - znear)
        M[2][2] = -1.0f / (zfar - znear);
        M[3][2] = -znear / (zfar - znear);

        M[3][3] = 1.0f;

        return M;
    }

    // TODO[Waleed]: add unittests
    inline static Mat4
    mat4_prespective(float fovy, float aspect, float znear, float zfar)
    {
        Mat4 M{};

        float h = tan(fovy / 2.0f);
        float w = aspect * h;

        M[0][0] = 1.0f / w;
        M[1][1] = 1.0f / h;

        // to map z to [-1, 1] use
        // M[2][2] = -(zfar + znear) / (zfar - znear)
        // M[3][2] = -(2.0f * zfar * znear) / (zfar - znear)
        M[2][2] = -zfar / (zfar - znear);
        M[2][3] = -1.0f;
        M[3][2] = -(zfar * znear) / (zfar - znear);

        return M;
    }

    inline static Mat4
    transpose(const Mat4 &M)
    {
        return Mat4{
            M[0][0], M[1][0], M[2][0], M[3][0],
            M[0][1], M[1][1], M[2][1], M[3][1],
            M[0][2], M[1][2], M[2][2], M[3][2],
            M[0][3], M[1][3], M[2][3], M[3][3]
        };
    }

    inline static float
    trace(const Mat4 &M)
    {
        return M[0][0] + M[1][1] + M[2][2] + M[3][3];
    }

    inline static float
    det(const Mat4 &M)
    {
        /*
        * before optimization:
            + M[0][0] * (
                + M[1][1] * (M[2][2] * M[3][3] - M[2][3] * M[3][2])
                - M[1][2] * (M[2][1] * M[3][3] - M[2][3] * M[3][1])
                + M[1][3] * (M[2][1] * M[3][2] - M[2][2] * M[3][1]))
            - M[0][1] * (
                + M[1][0] * (M[2][2] * M[3][3] - M[2][3] * M[3][2])
                - M[1][2] * (M[2][0] * M[3][3] - M[2][3] * M[3][0])
                + M[1][3] * (M[2][0] * M[3][2] - M[2][2] * M[3][0]))
            + M[0][2] * (
                + M[1][0] * (M[2][1] * M[3][3] - M[2][3] * M[3][1])
                - M[1][1] * (M[2][0] * M[3][3] - M[2][3] * M[3][0])
                + M[1][3] * (M[2][0] * M[3][1] - M[2][1] * M[3][0]))
            - M[0][3] * (
                + M[1][0] * (M[2][1] * M[3][2] - M[2][2] * M[3][1])
                - M[1][1] * (M[2][0] * M[3][2] - M[2][2] * M[3][0])
                + M[1][2] * (M[2][0] * M[3][1] - M[2][1] * M[3][0]));
        */
        return
            (M[0][0] * M[1][1] - M[0][1] * M[1][0]) * (M[2][2] * M[3][3] - M[2][3] * M[3][2]) -
            (M[0][0] * M[1][2] - M[0][2] * M[1][0]) * (M[2][1] * M[3][3] - M[2][3] * M[3][1]) +
            (M[0][0] * M[1][3] - M[0][3] * M[1][0]) * (M[2][1] * M[3][2] - M[2][2] * M[3][1]) +
            (M[0][1] * M[1][2] - M[0][2] * M[1][1]) * (M[2][0] * M[3][3] - M[2][3] * M[3][0]) -
            (M[0][1] * M[1][3] - M[0][3] * M[1][1]) * (M[2][0] * M[3][2] - M[2][2] * M[3][0]) +
            (M[0][2] * M[1][3] - M[0][3] * M[1][2]) * (M[2][0] * M[3][1] - M[2][1] * M[3][0]);
    }

    inline static Mat4
    adj(const Mat4 &M)
    {
        return Mat4{
            // m00
            + M[1][1] * (M[2][2] * M[3][3] - M[2][3] * M[3][2])
            - M[1][2] * (M[2][1] * M[3][3] - M[2][3] * M[3][1])
            + M[1][3] * (M[2][1] * M[3][2] - M[2][2] * M[3][1]),
            // m10
            - M[0][1] * (M[2][2] * M[3][3] - M[2][3] * M[3][2])
            + M[0][2] * (M[2][1] * M[3][3] - M[2][3] * M[3][1])
            - M[0][3] * (M[2][1] * M[3][2] - M[2][2] * M[3][1]),
            // m20
            + M[0][1] * (M[1][2] * M[3][3] - M[1][3] * M[3][2])
            - M[0][2] * (M[1][1] * M[3][3] - M[1][3] * M[3][1])
            + M[0][3] * (M[1][1] * M[3][2] - M[1][2] * M[3][1]),
            // m30
            - M[0][1] * (M[1][2] * M[2][3] - M[1][3] * M[2][2])
            + M[0][2] * (M[1][1] * M[2][3] - M[1][3] * M[2][1])
            - M[0][3] * (M[1][1] * M[2][2] - M[1][2] * M[2][1]),

            // m01
            - M[1][0] * (M[2][2] * M[3][3] - M[2][3] * M[3][2])
            + M[1][2] * (M[2][0] * M[3][3] - M[2][3] * M[3][0])
            - M[1][3] * (M[2][0] * M[3][2] - M[2][2] * M[3][0]),
            // m11
            + M[0][0] * (M[2][2] * M[3][3] - M[2][3] * M[3][2])
            - M[0][2] * (M[2][0] * M[3][3] - M[2][3] * M[3][0])
            + M[0][3] * (M[2][0] * M[3][2] - M[2][2] * M[3][0]),
            // m21
            - M[0][0] * (M[1][2] * M[3][3] - M[1][3] * M[3][2])
            + M[0][2] * (M[1][0] * M[3][3] - M[1][3] * M[3][0])
            - M[0][3] * (M[1][0] * M[3][2] - M[1][2] * M[3][0]),
            // m31
            + M[0][0] * (M[1][2] * M[2][3] - M[1][3] * M[2][2])
            - M[0][2] * (M[1][0] * M[2][3] - M[1][3] * M[2][0])
            + M[0][3] * (M[1][0] * M[2][2] - M[1][2] * M[2][0]),

            // m02
            + M[1][0] * (M[2][1] * M[3][3] - M[2][3] * M[3][1])
            - M[1][1] * (M[2][0] * M[3][3] - M[2][3] * M[3][0])
            + M[1][3] * (M[2][0] * M[3][1] - M[2][1] * M[3][0]),
            // m12
            - M[0][0] * (M[2][1] * M[3][3] - M[2][3] * M[3][1])
            + M[0][1] * (M[2][0] * M[3][3] - M[2][3] * M[3][0])
            - M[0][3] * (M[2][0] * M[3][1] - M[2][1] * M[3][0]),
            // m22
            + M[0][0] * (M[1][1] * M[3][3] - M[1][3] * M[3][1])
            - M[0][1] * (M[1][0] * M[3][3] - M[1][3] * M[3][0])
            + M[0][3] * (M[1][0] * M[3][1] - M[1][1] * M[3][0]),
            // m32
            - M[0][0] * (M[1][1] * M[2][3] - M[1][3] * M[2][1])
            + M[0][1] * (M[1][0] * M[2][3] - M[1][3] * M[2][0])
            - M[0][3] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]),

            // m03
            - M[1][0] * (M[2][1] * M[3][2] - M[2][2] * M[3][1])
            + M[1][1] * (M[2][0] * M[3][2] - M[2][2] * M[3][0])
            - M[1][2] * (M[2][0] * M[3][1] - M[2][1] * M[3][0]),
            // m13
            + M[0][0] * (M[2][1] * M[3][2] - M[2][2] * M[3][1])
            - M[0][1] * (M[2][0] * M[3][2] - M[2][2] * M[3][0])
            + M[0][2] * (M[2][0] * M[3][1] - M[2][1] * M[3][0]),
            // m23
            - M[0][0] * (M[1][1] * M[3][2] - M[1][2] * M[3][1])
            + M[0][1] * (M[1][0] * M[3][2] - M[1][2] * M[3][0])
            - M[0][2] * (M[1][0] * M[3][1] - M[1][1] * M[3][0]),
            // m33
            + M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1])
            - M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0])
            + M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0])
        };
    }

    inline static bool
    invertible(const Mat4 &M)
    {
        return det(M) != 0.0f;
    }

    inline static Mat4
    inverse(const Mat4 &M)
    {
        float d = det(M);
        if (d == 0)
            return Mat4{};

        return (1.0f / d) * adj(M);
    }
}
