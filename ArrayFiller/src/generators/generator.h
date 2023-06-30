//
// Created by JoachimWagner on 30.06.2023.
//

#pragma once

namespace generators {
    template<class T>
    class generator {
    public:
        virtual auto next() -> T = 0;
    };
}
