// Copyright Roberto De Ioris


#include "ExternalWindowActor.h"

// Sets default values
AExternalWindowActor::AExternalWindowActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ExternalWindowPtr = nullptr;
}

// Called when the game starts or when spawned
void AExternalWindowActor::BeginPlay()
{
	Super::BeginPlay();

	// Use The FSlateApplicationBase::GetDisplayMetrics() method to position a window
	// on a specific screen (FMonitorInfo contains monitor's data)

	ExternalWindowPtr = SNew(SWindow)
		.Title(FText::FromString(ExternalWindowTitle))
		.ScreenPosition(ExternalWindowPosition)
		.ClientSize(ExternalWindowSize)
		.UseOSWindowBorder(true)
		.AutoCenter(EAutoCenter::None)
		.SizingRule(ESizingRule::UserSized);

	ExternalWindowPtr->SetContent(SNew(SImage).Image(&ExternalImage));

	FSlateApplication::Get().AddWindow(ExternalWindowPtr.ToSharedRef());
}

// Called every frame
void AExternalWindowActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AExternalWindowActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (ExternalWindowPtr.IsValid())
	{
		FSlateApplication::Get().RequestDestroyWindow(ExternalWindowPtr.ToSharedRef());
	}

}