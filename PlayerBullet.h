#pragma once
#include "KamataEngine.h"
#include"MyMath.h"

class PlayerBullet
{
public:
	void Initialize(KamataEngine::Model* model, const KamataEngine::Vector3& position,const KamataEngine::Vector3& velocity);

	void Update();

	void Draw(const KamataEngine::Camera& camera);

	
	
	//弾の表示時間
	static const int32_t kLifeTime = 60 * 5;
	//デスタイマー
	int32_t deathTimer = kLifeTime;
	//デスフラグ
	bool isDead_ = false;

	bool IsDead() const { return isDead_; }



private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;

	// モデル
	KamataEngine::Model* model_;

	// 速度
	KamataEngine::Vector3 Bulletvelocity_;
	
};
