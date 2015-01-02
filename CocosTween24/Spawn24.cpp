#include "Spawn24.hpp"

namespace cocosTween24
{
Spawn24Ptr Spawn24::create(cocos2d::Node *target)
{
    auto s24 = std::make_shared<Spawn24>(target);

    return std::move(s24);
}

Spawn24::Spawn24(cocos2d::Node *target) : Player24(target) {}

cocos2d::ActionInterval *Spawn24::getAction()
{
    cocos2d::Vector<cocos2d::FiniteTimeAction *> actions(_tweens.size());
    for (auto tween : _tweens) {
        actions.pushBack(tween->getAction());
    }

    return cocos2d::Spawn::create(actions);
}

Spawn24Ptr Spawn24::addTweens(IInterval24Ptr tween)
{
    _tweens.push_back(tween);

    return shared_from_this();
}

Spawn24Ptr Spawn24::addTweens(const std::vector<IInterval24Ptr> &tweens)
{
    for (auto &tween : tweens) {
        addTweens(tween);
    }

    return shared_from_this();
}
} // namespace