#include "Remove.hpp"

namespace tweencc
{
RemovePtr Remove::create(cocos2d::Node *target)
{
    return std::move(std::make_shared<Remove>(target));
}

Remove::Remove(cocos2d::Node *target) : Player(this, target) {}

cocos2d::FiniteTimeAction *Remove::generateAction()
{
    cocos2d::FiniteTimeAction *action = generateActionWithoutTarget();

    auto target = getTarget();
    if (target) {
        action = cocos2d::TargetedAction::create(getTarget(), action);
    }

    return action;
}

cocos2d::FiniteTimeAction *Remove::generateActionWithoutTarget()
{
    return cocos2d::RemoveSelf::create();
}
} // namespace
