#ifndef __CocosTween24__Repeat24__
#define __CocosTween24__Repeat24__

#include <cocos2d.h>
#include "ITween24.h"

namespace cocosTween24
{
class Repeat24;
typedef std::shared_ptr<Repeat24> Repeat24Ptr;

class Repeat24 : public ITween24, public std::enable_shared_from_this<Repeat24>
{
public:
    static Repeat24Ptr create(cocos2d::Node *target, unsigned int times, ITween24Ptr tween);

    Repeat24(cocos2d::Node *target, unsigned int times, ITween24Ptr tween);
    virtual ~Repeat24();

    cocos2d::ActionInterval *getAction() override;
    void play() override;
    void stop() override;

    CC_SYNTHESIZE_READONLY(cocos2d::Node *, _target, Target);
    CC_SYNTHESIZE(unsigned int, _times, Times);

private:
    cocos2d::FiniteTimeAction *_playingAction;
    ITween24Ptr                _tween;
};
}

#endif /* defined(__CocosTween24__Repeat24__) */