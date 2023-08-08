// Generic Fighting Game

#include "UI/FNGHealthbarWidget.h"
#include "Components/ProgressBar.h"

void UFNGHealthbarWidget::SetHealthPercent(float Percent)
{
  if (!HealthProgressBar) return;
  HealthProgressBar->SetPercent(Percent);
}
