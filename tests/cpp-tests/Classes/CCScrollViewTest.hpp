//
//  CCScrollViewTest.hpp
//  cocos2d_tests
//
//  Created by 徳岡　純次 on 2017/08/04.
//
//

#ifndef CCScrollViewTest_hpp
#define CCScrollViewTest_hpp

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

using namespace cocos2d;
using namespace extension;

// Main Class
class CCScrollViewTest : public Layer, public ScrollViewDelegate
{
private:
    ScrollView *_scAdd;
    Layer *_lAdd;
    LayerColor *_lcAdd;
public:
    static Scene *scene();
    
    bool init();
    
    void onTouchesBegan(const std::vector<Touch*>& pTouches, Event *pEvent);
    void onTouchesMoved(const std::vector<Touch*>& pTouches, Event *pEvent);
    void onTouchesEnded(const std::vector<Touch*>& pTouches, Event *pEvent);
    
    void scrollViewDidScroll(ScrollView *view);
    void scrollViewDidZoom(ScrollView *view);
    
    CREATE_FUNC(CCScrollViewTest);
};


#endif /* CCScrollViewTest_hpp */
