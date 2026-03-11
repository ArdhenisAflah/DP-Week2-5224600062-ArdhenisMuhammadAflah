#include "ModifiedRewardRule.h"

int ModifiedRewardRule::ComputeReward(int finalScore, int targetScore) {
    // Modifikasi: Reward = baseScore (finalScore) + 2
    // Jika kalah (finalScore < targetScore), mungkin kita beri reward kecil saja atau tetap pakai rumus yang sama.
    // Asumsi: rumus berlaku baik menang maupun kalah agar beda dari standard.
    int reward = finalScore + 2;
    return reward;
}