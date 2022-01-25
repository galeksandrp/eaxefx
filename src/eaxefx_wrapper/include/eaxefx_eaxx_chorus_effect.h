/*

EAX OpenAL Extension

Copyright (c) 2020-2021 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
OR OTHER DEALINGS IN THE SOFTWARE.

*/


#ifndef EAXEFX_EAXX_CHORUS_EFFECT_INCLUDED
#define EAXEFX_EAXX_CHORUS_EFFECT_INCLUDED


#include <cstdint>

#include "eaxefx_al_object.h"
#include "eaxefx_al_symbols.h"
#include "eaxefx_eax_api.h"

#include "eaxefx_eaxx_eax_call.h"
#include "eaxefx_eaxx_effect.h"


namespace eaxefx
{


// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

using EaxxChorusEffectEaxDirtyFlagsValue = unsigned int;

struct EaxxChorusEffectEaxDirtyFlags
{
	EaxxChorusEffectEaxDirtyFlagsValue ulWaveform : 1;
	EaxxChorusEffectEaxDirtyFlagsValue lPhase : 1;
	EaxxChorusEffectEaxDirtyFlagsValue flRate : 1;
	EaxxChorusEffectEaxDirtyFlagsValue flDepth : 1;
	EaxxChorusEffectEaxDirtyFlagsValue flFeedback : 1;
	EaxxChorusEffectEaxDirtyFlagsValue flDelay : 1;
}; // EaxxChorusEffectEaxDirtyFlags

static_assert(sizeof(EaxxChorusEffectEaxDirtyFlags) == sizeof(EaxxChorusEffectEaxDirtyFlagsValue));

bool operator==(
	const EaxxChorusEffectEaxDirtyFlags& lhs,
	const EaxxChorusEffectEaxDirtyFlags& rhs) noexcept;

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

class EaxxChorusEffect final :
	public EaxxEffect
{
public:
	EaxxChorusEffect(
		ALuint al_effect_slot,
		const AlEfxSymbols* al_efx_symbols);


	void load() override;

	void dispatch(
		const EaxxEaxCall& eax_call) override;


private:
	const ALuint al_effect_slot_;
	const AlEfxSymbols* al_efx_symbols_;
	EfxEffectObject efx_effect_object_;

	EAXCHORUSPROPERTIES eax_;
	EAXCHORUSPROPERTIES eax_d_;
	EaxxChorusEffectEaxDirtyFlags eax_dirty_flags_{};


	void set_eax_defaults();


	void set_efx_waveform();

	void set_efx_phase();

	void set_efx_rate();

	void set_efx_depth();

	void set_efx_feedback();

	void set_efx_delay();

	void set_efx_defaults();


	void get(
		const EaxxEaxCall& eax_call);


	void validate_waveform(
		std::uint32_t ulWaveform);

	void validate_phase(
		std::int32_t lPhase);

	void validate_rate(
		float flRate);

	void validate_depth(
		float flDepth);

	void validate_feedback(
		float flFeedback);

	void validate_delay(
		float flDelay);

	void validate_all(
		const EAXCHORUSPROPERTIES& eax_all);


	void defer_waveform(
		std::uint32_t ulWaveform);

	void defer_phase(
		std::int32_t lPhase);

	void defer_rate(
		float flRate);

	void defer_depth(
		float flDepth);

	void defer_feedback(
		float flFeedback);

	void defer_delay(
		float flDelay);

	void defer_all(
		const EAXCHORUSPROPERTIES& eax_all);


	void defer_waveform(
		const EaxxEaxCall& eax_call);

	void defer_phase(
		const EaxxEaxCall& eax_call);

	void defer_rate(
		const EaxxEaxCall& eax_call);

	void defer_depth(
		const EaxxEaxCall& eax_call);

	void defer_feedback(
		const EaxxEaxCall& eax_call);

	void defer_delay(
		const EaxxEaxCall& eax_call);

	void defer_all(
		const EaxxEaxCall& eax_call);


	void apply_deferred();

	void set(
		const EaxxEaxCall& eax_call);
}; // EaxxChorusEffect

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


} // eaxefx


#endif // !EAXEFX_EAXX_CHORUS_EFFECT_INCLUDED
