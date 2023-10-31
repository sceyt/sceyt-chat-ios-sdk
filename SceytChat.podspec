Pod::Spec.new do |s|
  s.name         = "SceytChat"
  s.version      = "1.5.2"
  s.summary      = "SceytChat iOS Framework"
  s.description  = "Messaging and Chat API for Mobile Apps and Websites"
  s.homepage     = "https://sceyt.com"
  s.license      = "Commercial"
  s.authors      = { 
	"Ovsep Keropian" => "ovsep@sceyt.com"
  }
  s.source       = { :git => "https://github.com/sceyt/sceyt-chat-ios-sdk.git", :tag => "v#{s.version}" }
  s.requires_arc = true
  s.platform = :ios, "10.0"
  s.vendored_frameworks = 'Sources/SceytChat.xcframework'
  s.ios.frameworks = ["Foundation", "SystemConfiguration"]
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end
