//////////////////////////////////////////////////////////////////////////////
//
// This file is part of the Corona game engine.
// For overview and more information on licensing please refer to README.md 
// Home page: https://github.com/coronalabs/corona
// Contact: support@coronalabs.com
//
//////////////////////////////////////////////////////////////////////////////

#pragma once


#ifndef CORONALABS_CORONA_API_EXPORT
	#error This header file cannot be included by an external library.
#endif

#include "CoronaLabs\WinRT\IOperationResult.h"


// Forward declarations.
namespace CoronaLabs { namespace WinRT {
	ref class OperationResult;
} }


namespace CoronaLabs { namespace Corona { namespace WinRT { namespace Interop { namespace Graphics {

// Forward declarations.
interface class IBitmap;

/// <summary>Indicates if an operation has succeeded in producing a bitmap.</summary>
public ref class BitmapResult sealed : public CoronaLabs::WinRT::IOperationResult
{
	private:
		/// <summary>Creates a new result with the given information.</summary>
		/// <remarks>
		///  This is a private constructor that is only expected to be called by this class' static
		///  SucceededWith() and FailedWith() functions.
		/// </remarks>
		/// <param name="hasSucceeded">Set to true if the operation succeeded in producing a bitmap. Set to false if not.</param>
		/// <param name="message">
		///  Message providing details about the final results of the operation. If the operation failed to produce a bitmap,
		///  then this message is expected to explain why. Can be set to null or empty string.
		/// </param>
		/// <param name="bitmap">
		///  <para>The bitmap that was produced from the operation if succeeded.</para>
		///  <para>Set to null if the operation failed.</para>
		/// </param>
		BitmapResult(bool hasSucceeded, Platform::String^ message, IBitmap^ bitmap);

	public:
		/// <summary>Determines if the operation succeeded.</summary>
		/// <value>
		///  <para>Set to true if the operation was executed successfully.</para>
		///  <para>
		///   Set to false if the operation failed, in which case the Message property will likely provide details
		///   as to what went wrong.
		///  </para>
		/// </value>
		virtual property bool HasSucceeded { bool get(); }

		/// <summary>Determines if the operation failed.</summary>
		/// <value>
		///  <para>
		///   Set to true if the operation failed, in which case the Message property will likely provide details
		///   as to what went wrong.
		///  </para>
		///  <para>Set to false if the operation was executed successfully.</para>
		/// </value>
		virtual property bool HasFailed { bool get(); }

		/// <summary>Message providing details about the final result of the operation.</summary>
		/// <value>
		///  The message providing details about the final result of the operation.
		///  If the operation failed, then this message typically provides details indicating what went wrong.
		///  Operations that are successful typically provide an empty message string.
		/// </value>
		virtual property Platform::String^ Message { Platform::String^ get(); }

		/// <summary>Gets the bitmap that was produced from the operation if succeeded.</summary>
		/// <value>
		///  <para>Reference to the bitmap if the operation was successful.</para>
		///  <para>Set to null if the operation failed.</para>
		/// </value>
		property IBitmap^ Bitmap { IBitmap^ get(); }

		/// <summary>Creates a new success result object providing the given bitmap.</summary>
		/// <param name="bitmap">
		///  <para>The bitmap that was produced by the operation.</para>
		///  <para>Cannot be null or else an exception will be thrown.</para>
		/// </param>
		/// <returns>Returns a new result object set to succeeded and providing the given bitmap.</returns>
		static BitmapResult^ SucceededWith(IBitmap^ bitmap);

		/// <summary>Creates a new failure result object with the given error message.</summary>
		/// <remarks>This function is expected to be used if the operation failed to produce a bitmap.</remarks>
		/// <param name="message">
		///  <para>Message providing details as to why the operation failed to produce a bitmap.</para>
		///  <para>Can be null or empty string.</para>
		/// </param>
		/// <returns>Returns a new result object set to failed and with the given error message.</returns>
		static BitmapResult^ FailedWith(Platform::String^ message);

	private:
		CoronaLabs::WinRT::OperationResult^ fBaseResult;
		IBitmap^ fBitmap;
};

} } } } }	// namespace CoronaLabs::Corona::WinRT::Interop::Graphics
