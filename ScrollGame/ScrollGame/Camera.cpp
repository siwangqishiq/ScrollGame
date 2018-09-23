//
//  Camera.cpp
//  ScrollGame
//
//  Created by panyi  on 2018/9/7.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//

#include "Camera.hpp"

void Camera::moveTo(int x , int y)
{
    if(mLeft != x)
        mLeft = x;
   
    
    if(mLeft <= 0 )
        mLeft = 0;
    else if(mLeft >= mWorldWidth - mViewWidth)
        mLeft = mWorldWidth - mViewWidth;
    
    if(mTop != y)
        mTop = y;
    if(mTop <=0 )
        mTop = 0;
    else if(mTop >= mWorldHeight - mViewHeight)
        mTop = mWorldHeight - mViewHeight;
}

void Camera::toLeft()
{
    moveTo(mLeft - 10, mTop);
}

void Camera::toRight()
{
    moveTo(mLeft + 10, mTop);
}

void Camera::toUp()
{
    moveTo(mLeft, mTop - 10);
}

void Camera::toDown()
{
    moveTo(mLeft, mTop + 10);
}

void Camera::moveFar()
{
    changeDistance(mDistance + 0.01f);
}

void Camera::moveNear()
{
    changeDistance(mDistance - 0.01f);
}

void Camera::changeDistance(float newDistance){
    if(mDistance != newDistance){
        mDistance = newDistance;
        if(mDistance <= mMinDistance)
            mDistance = mMinDistance;
        if(mDistance >= mMaxDistance)
            mDistance = mMaxDistance;
        
        int newViewHeight = mWorldHeight * mDistance;
        int newViewWidth = mRatio * newViewHeight;
        
        mViewHeight = newViewHeight;
        mViewWidth = newViewWidth;
    }
}


