#include "RepeatForever.hpp"

namespace tweencc
{
RepeatForeverPtr RepeatForever::create(cocos2d::Node *target, IIntervalPtr tween)
{
    auto r = std::make_shared<RepeatForever>(target, tween);

    return std::move(r);
}

RepeatForever::RepeatForever(cocos2d::Node *target, IIntervalPtr tween) : Player(this, target), _tween(tween) {}

cocos2d::ActionInterval *RepeatForever::generateAction()
{
    auto action = cocos2d::TargetedAction::create(getTarget(), _tween->generateAction());

    return cocos2d::RepeatForever::create(action);
}

cocos2d::ActionInterval *RepeatForever::generateActionWithoutTarget()
{
    return cocos2d::RepeatForever::create(_tween->generateAction());
}
} // namespace
