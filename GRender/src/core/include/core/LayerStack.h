#pragma once

#include <vector>

#include "core/Layer.h"

namespace GRender
{
    class LayerStack
    {
    public:
        LayerStack() = default;
        ~LayerStack()
        {
            for (auto& layer : layers_)
            {
                layer->OnDetach();
                delete layer;
            }
        }

        void PushLayerOverlay(Layer* layer)
        {
            layers_.emplace_back(layer);
            ++layerInsertIndex;
        }
        void PopLayerOverlay(Layer* layer)
        {
            auto iter = std::find(layers_.begin(), layers_.begin() + layerInsertIndex, layer);
            if (iter != layers_.begin() + layerInsertIndex)
            {
                layer->OnDetach();
                layers_.erase(iter);
                --layerInsertIndex;
            }
        }

        std::vector<Layer*>::iterator begin() { return layers_.begin(); }
        std::vector<Layer*>::iterator end() { return layers_.end(); }
        std::vector<Layer*>::reverse_iterator rbegin() { return layers_.rbegin(); }
        std::vector<Layer*>::reverse_iterator rend() { return layers_.rend(); }

    private:
        std::vector<Layer*> layers_;
        size_t layerInsertIndex = 0;
    };
}  // namespace GRender