// Copyright Roberto De Ioris

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Widgets/Images/SImage.h"
#include "ExternalWindowActor.generated.h"

UCLASS()
class ETXERNALWINDOWS_API AExternalWindowActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExternalWindowActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSlateBrush ExternalImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D ExternalWindowPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector2D ExternalWindowSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ExternalWindowTitle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	TSharedPtr<SWindow> ExternalWindowPtr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

};
