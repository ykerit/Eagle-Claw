#pragma once

#include <string>

namespace EagleClaw
{
    class Layer
    {
    public:
        Layer(const std::string& name) : name_(name) { }
        virtual ~Layer() = default;
        virtual void OnAttach() { }

        virtual void OnDetach() { }

        virtual void OnUpdate() { }

        virtual void OnImGuiRender() { }

        const std::string GetName() const { return name_; }

    private:
        std::string name_;
    };

}  // namespace EagleClaw