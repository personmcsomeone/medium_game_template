// bullet.cpp
#include "bullet.h"

//constexpr int maxBullets = 10;
//constexpr int maxBulletLife = 10;
//constexpr float bulletSpeed = 10.0f;


void InitializeBullet(Bullet bullet[maxBullets], Vector3 pos, Vector3 dir){
    for(int i = 0; i < maxBullets; i++){
        if(!bullet[i].isActive){
            bullet[i].isActive = 1;
            bullet[i].pos = pos;
            bullet[i].dir = Vector3Scale(dir, 1.0 / Vector3Length(dir)); //normalized unit vector
            break; // stop making bullets.
        }
        else{ //bullet is already active, do nothing
        }
    }
}

void UpdateBullets(Bullet bullet[maxBullets]){
    for(int i = 0; i < maxBullets; i++){
        //ensure bullet is active
        if(bullet[i].isActive){
            //update time
            bullet[i].lifetime += GetFPS();
            //check if bullet needs to die, remove it
            if(bullet[i].lifetime >= maxBulletLife){
                bullet[i].lifetime = 0.0;
                bullet[i].isActive = 0;
                continue;
            }
            //update position
            Vector3Add(
                bullet[i].pos,
                Vector3Scale(bullet[i].dir, bulletSpeed/GetFPS())
            );
        }
        else{ //bullet is not active, do nothing
        }
    }
}