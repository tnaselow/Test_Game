#pragma once

#include "Component.h"
#include <vector>

class Entity;
class ParticleEmitter : public Component
{
	public:
		std::vector<Entity> particles;


		Texture2D mTexture;   // which texture should be on the particles
		bool      mLoop;      // should the spawner continously spawn
		
		unsigned  mEmitCount; // number of particles to emit
		unsigned  mEmitRate; // particles per second

		float     mSizeVariance; // randomness of size in each particle

		float     mSize;      // size of the particle
		float     mLifeTime;  // lifetime of the particle
		float     mLifeTimeVariance; // the variance of the lifetime

		float     mSpinRate;   // rate at which the particles spin

		float     mFill;  // amount of the possible Area to spawn particles

		Vector3   mStartVelocity;  // starting velocity
		Vector3   mRandomVelocity; // randomly changes velocity

		Vector3   mEmitterSize;  // area to spawn particles in

	private:
		void spawnParticle();
};