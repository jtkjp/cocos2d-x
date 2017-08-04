//
//  CCScrollViewTest.cpp
//  cocos2d_tests
//
//  Created by 徳岡　純次 on 2017/08/04.
//
//

#include "CCScrollViewTest.hpp"

Scene* CCScrollViewTest::scene()
{
    Scene *scene = Scene::create();
    CCScrollViewTest *layer = CCScrollViewTest::create();
    scene->addChild(layer);
    return scene;
}

bool CCScrollViewTest::init() {
    
    if ( !Layer::init() )
    {
        return false;
    }
    CCLOG("CCScrollViewTest::init");
    
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesBegan = CC_CALLBACK_2(CCScrollViewTest::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(CCScrollViewTest::onTouchesMoved, this);
    listener->onTouchesEnded = CC_CALLBACK_2(CCScrollViewTest::onTouchesEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    auto lcBG = LayerColor::create(Color4B::WHITE);
    this->addChild(lcBG);
    
    //スクロールビュー 操作性向上のため後でViewSizeを変更する
    this->_scAdd = ScrollView::create(cocos2d::Size(300, 150));
    this->_scAdd->setPosition(Vec2(50, 50));
    this->_scAdd->setSwallowTouches(false);
    
    //コンテナ　横：コンテンツサイズ 縦：スクロールビューの当たり判定
    this->_lAdd = LayerColor::create(Color4B(0, 0, 0, 0), 600, 150);
    
    //後ろの色 ここにアイテムを載せる
    this->_lcAdd = LayerColor::create(Color4B(0, 200, 0, 255), 600, 150);
    this->_lAdd->addChild(this->_lcAdd);
    
    this->_scAdd->setDelegate(this);
    this->_scAdd->setBounceable(true);
    this->_scAdd->setContentSize(cocos2d::Size(600, 150));
    this->_scAdd->setContainer(this->_lAdd);
    this->_scAdd->setViewSize(cocos2d::Size(300, 150));
    this->_scAdd->setDirection(ScrollView::Direction::HORIZONTAL);
    //this->_scAdd->setContentOffset(0);
    this->addChild(this->_scAdd);
    
    return true;
}

void CCScrollViewTest::onTouchesBegan(const std::vector<Touch*>& pTouches, Event *pEvent)
{
    Layer::onTouchesBegan(pTouches, pEvent);
    
    for (int touchCnt=0; touchCnt<pTouches.size(); touchCnt++)
    {
        Touch *pTouch = pTouches[touchCnt];
        Vec2 worldpos = Director::getInstance()->convertToGL(pTouch->getLocationInView());
        int touchId = pTouch->getID();
        if(touchId == 0){
            //スクロール内のタッチ座標で考える
            if(!this->_scAdd->getBoundingBox().containsPoint(worldpos)){
                CCLOG("スクロール外 %.0f:%.0f", worldpos.x, worldpos.y);
            }else{
                CCLOG("スクロール内 %.0f:%.0f", worldpos.x, worldpos.y);
            }
        }
    }
}

void CCScrollViewTest::onTouchesMoved(const std::vector<Touch*>& pTouches, Event *pEvent)
{
    Layer::onTouchesMoved(pTouches, pEvent);
    
}

void CCScrollViewTest::onTouchesEnded(const std::vector<Touch*>& pTouches, Event *pEvent)
{
    Layer::onTouchesEnded(pTouches, pEvent);
    
}

void CCScrollViewTest::scrollViewDidScroll(ScrollView *view)
{
    
}

void CCScrollViewTest::scrollViewDidZoom(ScrollView *view)
{
    
}
