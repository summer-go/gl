//
// Created by baidu on 2022/2/14.
//

#ifndef SUMMERGL_ANIMDATA_H
#define SUMMERGL_ANIMDATA_H
#pragma once

#include<glm/glm.hpp>

struct BoneInfo
        {
    /*id is index in finalBoneMatrices*/
    int id;

    /*offset matrix transforms vertex from model space to bone space*/
    glm::mat4 offset;

        };
#pragma once
#endif //SUMMERGL_ANIMDATA_H
