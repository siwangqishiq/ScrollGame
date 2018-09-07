//
//  Camera.hpp
//  ScrollGame
//
//  Created by panyi  on 2018/9/7.
//  Copyright © 2018年 xinlan.com. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

class Camera{
public:
    int mViewWidth;
    int mViewHeight;
    int mLeft;
    int mTop;
    
    Camera(int vw,int vh,float r , int ww,int wh):
    mViewWidth(vw),
    mViewHeight(vh),
    mRatio(r),
    mDistance(1),
    mWorldWidth(ww),
    mWorldHeight(wh)
    {
        mLeft = 0;
        mTop = 0;
        
        mMinDistance = 0.5f;
        if(mWorldWidth >= mWorldHeight){
            mMaxDistance = (float)mWorldHeight / mViewHeight;
        }else{
            mMaxDistance = (float)mWorldWidth / mViewWidth;
        }
        if(mMaxDistance < 1.0f)
            mMaxDistance = 1.1f;
    }
    
    //void update();
    void moveTo(int x , int y);
    void moveFar();
    void moveNear();
    
    void toLeft();
    void toRight();
    void toUp();
    void toDown();
private:
    float mRatio;//w / h
    float mDistance;
    
    int mWorldWidth;
    int mWorldHeight;
    
    float mMinDistance = 0.5f;
    float mMaxDistance = 2.0f;
    
    void changeDistance(float newDistance);
};

#endif /* Camera_hpp */
