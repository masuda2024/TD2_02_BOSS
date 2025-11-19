#pragma once
#include "KamataEngine.h"
#include"MyMath.h"

class PlayerBullet
{
public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& position);

	void Update();

	void Draw();

	// 終了フラグ
	bool isFinished_ = false;
	
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

	// カメラ
	KamataEngine::Camera* camera_;

	// 速度
	KamataEngine::Vector3 Bulletvelocity_;
	
};
