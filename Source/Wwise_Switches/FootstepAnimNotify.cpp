// Fill out your copyright notice in the Description page of Project Settings.


#include "FootstepAnimNotify.h"
#include "AkGameplayStatics.h"

#include "PhysicalMaterials/PhysicalMaterial.h"

void UFootstepAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) {
	FHitResult hit;
	FCollisionQueryParams QueryParams;

	if(GetWorld()->GetFirstPlayerController()) {
		auto player = GetWorld()->GetFirstPlayerController()->GetPawn();
		if(!player) {
			return;
		}
		auto playerLoc = player->GetActorLocation();
		QueryParams.AddIgnoredActor(player);

		// not set by default like in blueprints!!
		QueryParams.bReturnPhysicalMaterial = true;

		auto end = playerLoc + FVector{0.f, 0.f, -1000.f};
		GetWorld()->LineTraceSingleByChannel(hit, playerLoc, end, ECC_Visibility, QueryParams);

		auto AudioDevice = FAkAudioDevice::Get();

		if(!hit.PhysMaterial.IsValid()) {
			return;
		}

		FName switchName;
		if(hit.PhysMaterial->SurfaceType == SurfaceType1) {
			switchName = "Concrete";
			if(GEngine) {
				GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("surface type Concrete"));
			}
		} else if(hit.PhysMaterial->SurfaceType == SurfaceType2) {
			switchName = "Gravel";
			if(GEngine) {
				GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("surface type Gravel"));
			}
		}
		AudioDevice->SetSwitch(*switchGroup.ToString(), *switchName.ToString(), player);
		UAkGameplayStatics::PostEventByName("FootstepsEvent", player);
	}
}
