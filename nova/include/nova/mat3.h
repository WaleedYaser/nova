#pragma once

#include "nova/types.h"
#include "nova/math.h"

namespace nova
{
    inline static bool
    operator==(const Mat3 &A, const Mat3 &B)
    {
        return
            A[0][0] == B[0][0] && A[0][1] == B[0][1] && A[0][2] == B[0][2] &&
            A[1][0] == B[1][0] && A[1][1] == B[1][1] && A[1][2] == B[1][2] &&
            A[2][0] == B[2][0] && A[2][1] == B[2][1] && A[2][2] == B[2][2];
    }

    inline static bool
    operator!=(const Mat3 &A, const Mat3 &B)
    {
        return !(A == B);
    }

    inline static Mat3
    operator+(const Mat3 &A, const Mat3 &B)
    {
        return Mat3{
            A[0][0] + B[0][0], A[0][1] + B[0][1], A[0][2] + B[0][2],
            A[1][0] + B[1][0], A[1][1] + B[1][1], A[1][2] + B[1][2],
            A[2][0] + B[2][0], A[2][1] + B[2][1], A[2][2] + B[2][2]
        };
    }

    inline static Mat3 &
    operator+=(Mat3 &A, const Mat3 &B)
    {
        A = A + B;
        return A;
    }

    inline static Mat3
    operator-(const Mat3 &M)
    {
        return Mat3{
            -M[0][0], -M[0][1], -M[0][2],
            -M[1][0], -M[1][1], -M[1][2],
            -M[2][0], -M[2][1], -M[2][2]
        };
    }

    inline static Mat3
    operator-(const Mat3 &A, const Mat3 &B)
    {
        return Mat3{
            A[0][0] - B[0][0], A[0][1] - B[0][1], A[0][2] - B[0][2],
            A[1][0] - B[1][0], A[1][1] - B[1][1], A[1][2] - B[1][2],
            A[2][0] - B[2][0], A[2][1] - B[2][1], A[2][2] - B[2][2]
        };
    }

    inline static Mat3 &
    operator-=(Mat3 &A, const Mat3 &B)
    {
        A = A - B;
        return A;
    }

    inline static Mat3
    operator*(const Mat3 &M, float f)
    {
        return Mat3{
            M[0][0] * f, M[0][1] * f, M[0][2] * f,
            M[1][0] * f, M[1][1] * f, M[1][2] * f,
            M[2][0] * f, M[2][1] * f, M[2][2] * f
        };
    }

    inline static Mat3
    operator*(float f, const Mat3 &M)
    {
        return M * f;
    }

    inline static Mat3 &
    operator*=(Mat3 &M, float f)
    {
        M = M * f;
        return M;
    }

    inline static Vec3
    operator*(const Vec3 &v, const Mat3 &M)
    {
        return Vec3{
            v.x * M[0][0] + v.y * M[1][0] + v.z * M[2][0],
            v.x * M[0][1] + v.y * M[1][1] + v.z * M[2][1],
            v.x * M[0][2] + v.y * M[1][2] + v.z * M[2][2]
        };
    }

    inline static Mat3
    operator*(const Mat3 &A, const Mat3 &B)
    {
        Mat3 C;

        C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0] + A[0][2] * B[2][0];
        C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1] + A[0][2] * B[2][1];
        C[0][2] = A[0][0] * B[0][2] + A[0][1] * B[1][2] + A[0][2] * B[2][2];

        C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0] + A[1][2] * B[2][0];
        C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1] + A[1][2] * B[2][1];
        C[1][2] = A[1][0] * B[0][2] + A[1][1] * B[1][2] + A[1][2] * B[2][2];

        C[2][0] = A[2][0] * B[0][0] + A[2][1] * B[1][0] + A[2][2] * B[2][0];
        C[2][1] = A[2][0] * B[0][1] + A[2][1] * B[1][1] + A[2][2] * B[2][1];
        C[2][2] = A[2][0] * B[0][2] + A[2][1] * B[1][2] + A[2][2] * B[2][2];

        return C;
    }

    inline static Mat3
    operator/(const Mat3 &M, float f)
    {
        return Mat3{
            M[0][0] / f, M[0][1] / f, M[0][2] / f,
            M[1][0] / f, M[1][1] / f, M[1][2] / f,
            M[2][0] / f, M[2][1] / f, M[2][2] / f
        };
    }

    inline static Mat3
    operator/(float f, const Mat3 &M)
    {
        return M / f;
    }

    inline static Mat3 &
    operator/=(Mat3 &M, float f)
    {
        M = M / f;
        return M;
    }

    inline static Mat3
    mat3_identity()
    {
        return Mat3{
            1, 0, 0,
            0, 1, 0,
            0, 0, 1
        };
    }

    inline static Mat3
    mat3_translation_2d(float dx, float dy)
    {
        return Mat3{
             1,  0, 0,
             0,  1, 0,
            dx, dy, 1
        };
    }

    inline static Mat3
    mat3_translation_2d(const Vec2 &translation)
    {
        return mat3_translation_2d(translation.x, translation.y);
    }

    inline static Mat3
    mat3_rotation_2d(float theta)
    {
        float c = cos(theta);
        float s = sin(theta);

        return Mat3{
             c, s, 0,
            -s, c, 0,
             0, 0, 1
        };
    }

    inline static Mat3
    mat3_scaling_2d(float sx, float sy)
    {
        return Mat3{
            sx,  0, 0,
             0, sy, 0,
             0,  0, 1
        };
    }

    inline static Mat3
    mat3_scaling_2d(Vec2 s)
    {
        return mat3_scaling_2d(s.x, s.y);
    }

    inline static Mat3
    mat3_rotation_x(float pitch)
    {
        float c = cos(pitch);
        float s = sin(pitch);

        return Mat3{
            1,  0, 0,
            0,  c, s,
            0, -s, c};
    }

    inline static Mat3
    mat3_rotation_y(float yaw)
    {
        float c = cos(yaw);
        float s = sin(yaw);

        return Mat3{
            c, 0, -s,
            0, 1,  0,
            s, 0,  c};
    }

    inline static Mat3
    mat3_rotation_z(float roll)
    {
        float c = cos(roll);
        float s = sin(roll);

        return Mat3{
             c, s, 0,
            -s, c, 0,
             0, 0, 1};
    }

    inline static Mat3
    mat3_rotation_axis(const Vec3 &axis, float angle)
    {
        float c = cos(angle);
        float s = sin(angle);

        float x = axis.x;
        float y = axis.y;
        float z = axis.z;

        return Mat3{
            c + (1-c)*x*x  , (1-c)*x*y + s*z, (1-c)*x*z - s*y,
            (1-c)*x*y - s*z, c + (1-c)*y*y  , (1-c)*y*z + s*x,
            (1-c)*x*z + s*y, (1-c)*y*z - s*x, c + (1-c)*z*z
        };
    }

    inline static Mat3
    mat3_euler(float pitch, float head, float roll)
    {
        float sh = sin(head);
        float ch = cos(head);
        float sp = sin(pitch);
        float cp = cos(pitch);
        float sr = sin(roll);
        float cr = cos(roll);

        // order yxz
        return Mat3{
             cr*ch - sr*sp*sh, sr*ch + cr*sp*sh, -cp*sh,
            -sr*cp           , cr*cp           ,  sp   ,
             cr*sh + sr*sp*ch, sr*sh - cr*sp*ch,  cp*ch
        };
    }

    inline static Mat3
    mat3_euler(const Vec3 &rotation)
    {
        return mat3_euler(rotation.x, rotation.y, rotation.z);
    }

    inline static Vec3
    mat3_euler_angles(const Mat3 &E)
    {
        return Vec3{
            asin(E[1][2]),
            atan2(-E[0][2], E[2][2]),
            atan2(-E[1][0], E[1][1])
        };
    }

    inline static Mat3
    mat3_scaling(float sx, float sy, float sz)
    {
        return Mat3{
            sx,  0,  0,
             0, sy,  0,
             0,  0, sz};
    }

    inline static Mat3
    mat3_scaling(const Vec3 &scaling)
    {
        return mat3_scaling(scaling.x, scaling.y, scaling.z);
    }

    inline static Mat3
    mat3_shearing_xy(float s)
    {
        return Mat3{
            1, 0, 0,
            s, 1, 0,
            0, 0, 1
        };
    }

    inline static Mat3
    mat3_shearing_xz(float s)
    {
        return Mat3{
            1, 0, 0,
            0, 1, 0,
            s, 0, 1
        };
    }

    inline static Mat3
    mat3_shearing_yx(float s)
    {
        return Mat3{
            1, s, 0,
            0, 1, 0,
            0, 0, 1
        };
    }

    inline static Mat3
    mat3_shearing_yz(float s)
    {
        return Mat3{
            1, 0, 0,
            0, 1, 0,
            0, s, 1
        };
    }

    inline static Mat3
    mat3_shearing_zx(float s)
    {
        return Mat3{
            1, 0, s,
            0, 1, 0,
            0, 0, 1
        };
    }

    inline static Mat3
    mat3_shearing_zy(float s)
    {
        return Mat3{
            1, 0, 0,
            0, 1, s,
            0, 0, 1
        };
    }

    inline static Mat3
    transpose(const Mat3 &M)
    {
        return Mat3{
            M[0][0], M[1][0], M[2][0],
            M[0][1], M[1][1], M[2][1],
            M[0][2], M[1][2], M[2][2]
        };
    }

    inline static float
    trace(const Mat3 &M)
    {
        return M[0][0] + M[1][1] + M[2][2];
    }

    inline static float
    det(const Mat3 &M)
    {
        return
            + M[0][0] * (M[1][1] * M[2][2] - M[1][2] * M[2][1])
            - M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0])
            + M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]);
    }

    inline static Mat3
    adj(const Mat3 &M)
    {
        return Mat3{
            //[0][0]
            + (M[1][1] * M[2][2] - M[1][2] * M[2][1]),
            //[1][0]
            - (M[0][1] * M[2][2] - M[0][2] * M[2][1]),
            //[2][0]
            + (M[0][1] * M[1][2] - M[0][2] * M[1][1]),

            //[0][1]
            - (M[1][0] * M[2][2] - M[1][2] * M[2][0]),
            //[1][1]
            + (M[0][0] * M[2][2] - M[0][2] * M[2][0]),
            //[2][1]
            - (M[0][0] * M[1][2] - M[0][2] * M[1][0]),

            //[0][2]
            + (M[1][0] * M[2][1] - M[1][1] * M[2][0]),
            //[1][2]
            - (M[0][0] * M[2][1] - M[0][1] * M[2][0]),
            //[2][2]
            + (M[0][0] * M[1][1] - M[0][1] * M[1][0])
        };
    }

    inline static bool
    invertible(const Mat3 &M)
    {
        return det(M) != 0.0f;
    }

    inline static Mat3
    inverse(const Mat3 &M)
    {
        float d = det(M);
        if (d == 0)
            return Mat3{};

        return (1.0f / d) * adj(M);
    }
}
